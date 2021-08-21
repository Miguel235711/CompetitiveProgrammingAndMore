#include<bits/stdc++.h>
#define maxLength 20008
#define limMap 30008

using namespace std ; 


struct maping {
    int x,y0,y1;
    bool born; //sort by x increasingly
    bool operator<(maping other)const{
        return x < other.x ;  
    }
    maping(){}
    maping(int x, int y0, int y1, bool born){
        this-> x = x;
        this-> y0 = y0;
        this-> y1 = y1;
        this-> born = born;
    }
};

maping mapings[maxLength];
int n,n2,quantums,quantumSize;
int maxY = 0 , minY = limMap ; 

//sqrt decomposition

struct es{
    int value,index;
    bool operator<(es other)const{
        return value < other.value;
    }
} nums[limMap] ;
int lazy[180],lastZero[180],lastSmallestNumber[180];
bool alreadybuilt[180];

int getSegment(int pos){
    return (pos-1)/quantumSize + 1 ; 
}

int getBegOfSegment(int pos){
    return (getSegment(pos)-1)*quantumSize+1;
}

int getBegWithSegment(int segment){
    return (segment-1)*quantumSize+1;
}
int getEndOfSegment(int pos){
    return min(getSegment(pos)*quantumSize,maxY);
}

int getEndWithSegment(int segment){
    return min(segment*quantumSize,maxY);
}

void reconstructSegment(int y, int yExtra,int dif, int inc){
    const int segmentEnd = getEndOfSegment(y) , segmentBeg = getBegOfSegment(y);
    int segment = getSegment(y);
    alreadybuilt[segment]=true;
    for(int posSegment = segmentBeg; posSegment <= segmentEnd ; posSegment ++ ) {
        nums[posSegment].value += lazy[segment];
        if ( ( (inc==1 && nums[posSegment].index >=y) || (inc==-1 &&nums[posSegment].index <=y) ) && nums[posSegment].index <= yExtra ){
            nums[posSegment].value += dif ; 
        }
    }
    lazy[segment]=0;//because it has been used (Warning!)
    //sort nums in segment
    sort(nums+segmentBeg,nums+segmentEnd+1);
    //save the next for each range ending and calculate last zero
    lastZero[segment]=segmentBeg-1;
    lastSmallestNumber[segment]=segmentEnd;
    /*cout << "segment nums:\n";
    for(int i = segmentBeg ; i <= segmentEnd ; i ++ ){
        cout << nums[i].value << " " ; 
    }
    cout << "\n";
    cout << "dif: " << dif << "\n";*/
    for(int i = segmentBeg ;  i< segmentEnd ; i ++ ){
        if(nums[i].value!=nums[i+1].value){
            lastSmallestNumber[segment] = i ;
            break;
        }
    }
    if(nums[lastSmallestNumber[segment]].value==0){
        //special case
        lastZero[segment]=lastSmallestNumber[segment];
    }
    //cout << "last Zero: " << lastZero[segment] << "\n";
}

void update(int y0, int y1, int dif){ //y0 and y1 need to be normalized to range from 1 to ...
    int segmentY0=getSegment(y0),segmentY1 = getSegment(y1);
    //cout << "quantumSize: " << quantumSize << "\n";
    //cout << "***update: " << "y0 " << y0 << " y1: " << y1 << " segmentY0: " << segmentY0 << " segmentY1: " << segmentY1 << "\n";
    if(segmentY0<segmentY1){
        reconstructSegment(y0,INT_MAX,dif,1);
        reconstructSegment(y1,INT_MAX,dif,-1);
        segmentY0++,segmentY1--;
        //update 
        //cout << "update: " << segmentY0 << " " << segmentY1 << "\n";
        for(; segmentY0 <= segmentY1 ; segmentY0++){
            int segmentBeg = getBegWithSegment(segmentY0);
            //! beg
            if(alreadybuilt[segmentY0]){
                lazy[segmentY0]+=dif;
            }else{
                reconstructSegment(segmentBeg,INT_MAX,dif,1);
            }
            //! end
            if(lazy[segmentY0]+nums[segmentBeg].value==0){
               lastZero[segmentY0] = lastSmallestNumber[segmentY0] ; 
            }else{
                lastZero[segmentY0] = segmentBeg - 1 ; //!
            }
        }
    }else{
        //cout << "updateSpecial Case: " << "y0 " << y0 << " y1: " << y1 << " segmentY0: " << segmentY0 << " segmentY1: " << segmentY1 << "\n";
        reconstructSegment(y0,y1,dif,1);
    }
}

int countNonZerosWithBruteForce(int beg,int ending){
    int ans = 0 ; 
    int segment = getSegment(beg);
    for(;beg <= ending ; beg ++){
        if(nums[beg].value+lazy[segment]){
            ans++;
        }
    }
    return ans;
}

int query(int y0,int y1){//y0 and y1 need to be normalized to range from 1 to ...
    int segmentY0=getSegment(y0),segmentY1 = getSegment(y1),ans=0;
    if(segmentY0<segmentY1){
        //calculate  subsegments
        ans+=countNonZerosWithBruteForce(y0,getEndOfSegment(y0))+countNonZerosWithBruteForce(getBegOfSegment(y1),y1);
        //cout << "after bruteForce ans= " << ans << "\n";
        segmentY0++,segmentY1--;
        for(; segmentY0 <= segmentY1 ; segmentY0++){
            int segmentEnd = getEndWithSegment(segmentY0);
            /*if(segmentY0==3){
                cout << "supposed to add: " << segmentEnd-lastZero[segmentY0] << "\n";
            }*/
            if(alreadybuilt[segmentY0]){//!!
                //cout << "entered:\n";
                ans += segmentEnd-lastZero[segmentY0];
            }
        }
    }else{
        //same segment
        ans+=countNonZerosWithBruteForce(y0,y1);
    }
    return ans ; 
}

int calculateAreaRects(int width){
    //make query from 1 to maxY
    //cout << "width: " << width << "\n";
    //cout << "maxY: " << maxY << "\n";
    //cout << "calculateAreaRects: " << 1 << " " << maxY << "width: " << width << "query result: " << query(1,maxY) << "\n"; 
    return query(1,maxY)*width;
}

void pushRect(maping mp){
    //cout << "pushRect: " << mp.y0 << " " <<mp.y1-1 << "\n";
    update(mp.y0,mp.y1-1,1);//!
}

void popRect(maping mp){
    //cout << "popRect: " << mp.y0 << " " <<mp.y1-1 << "\n";
    update(mp.y0,mp.y1-1,-1);//!
}

void calcArea(){
    int ans = 0;
    int previousX = mapings[1].x;
    for(int i = 1 ; i <= n2 ;){
        int currentX = mapings[i].x;
        if(mapings[i].x!=previousX){
            ans+=calculateAreaRects(mapings[i].x-previousX);
            previousX = mapings[i].x;
        }
        for(;i <= n2 && mapings[i].x == currentX;i++){
            if(mapings[i].born){
                pushRect(mapings[i]);
                /*for(int i = 1 ; i <= 6 ; i ++){
                    cout << "after pushing: "<< " "  << lazy[i] << " " << lastZero[i] << "\n";
                }
                for(int i = 1 ; i <= maxY ; i ++){
                    cout << "in position i: " << i << " -> " << nums[i].value << "\n";
                }*/
            }else{
                popRect(mapings[i]);
            }
        }
    }
    cout << ans << "\n";
}

void normalize(){
    for(int i = 1 ; i <= n2 ; i ++){
        mapings[i].y0 = mapings[i].y0 - minY + 1; 
        mapings[i].y1 = mapings[i].y1 - minY + 1;
        //cout << "in normalization: " << mapings[i].y0 << " " << mapings[i].y1 << "\n";
    }
    for(int i = 1 ; i <= maxY ; i ++){
        nums[i].index=i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n ; 
    n2 = n << 1 ; 
    int x1,x2,y1,y2;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> x1 >> y1 >> x2 >> y2 ; 
        mapings[i*2-1] = maping(x1,y1,y2,true);
        mapings[i*2] = maping(x2,y1,y2,false);
        minY = min(minY,y1);
        maxY=max(maxY,y2);
    }
    normalize();
    maxY = maxY - minY ; //!
    quantumSize = sqrt(maxY);
    quantums = maxY/quantumSize + maxY%quantumSize?1:0; 
    sort(mapings+1,mapings+n2+1);
    calcArea();
    return 0;
}