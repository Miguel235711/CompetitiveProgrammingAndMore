#define MAXN 100000

int n;
int a[MAXN];
struct seg{
    int l,r,v;
}sg[MAXN*4]; //indexed from 1

int build(int v,int l,int r){
    sg[v].l=l;
    sg[v].r=r;
    if(l==r){  
        //it is leaf
        sg[v].v=a[l];
    }else{
        //it is not leaf
        int v2 = v<<1,m=(l+r)>>1;
        sg[v].v = build(v2,l,m) + build(v2+1,m+1,r);
    }
    return sg[v].v;
}
int sum(int v,int l,int r){
    if(l>sg[v].r || r < sg[v].l)
        return 0;
    if(l<=sg[v].l&&sg[v].r<=r)
        return sg[v].v;
    int v2=v<<1;
    return sum(v2,l,r)+sum(v2+1,l,r);
}
int update(int v,int i,int nV){ /// ****INCORRECT!!!
    int v2=v<<1;
    return sg[v].v = sg[v].l==sg[v].r ? nV : update(v2+(i>sg[v2].r?1:0),i,nV);
    /*if(sg[v].l==sg[v].r)
        sg[v].v = nV;
    else{
        int v2 = v<<1;
        if(i<=sg[v2].r)
            sg[v].v=update(v2,i,nV);
        else
            sg[v].v=update(v2+1,i,nV);
    }
    return sg[v].v;*/
}