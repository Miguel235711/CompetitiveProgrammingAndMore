import java.util.ArrayList;

public class Main{
  static final int lim = 10;
  static Integer[] arr1=new Integer[lim];
  static ArrayList<Integer> arr3=new ArrayList<>();
  static <T> void print(T[]a){
    for(int i=0;i<a.length;i++)
        System.out.print(a[i]+" ");
    System.out.printf("\n");
  }
  static <T> void print(ArrayList<T>a){
    for(T e:a)
      System.out.print(e+" ");
    System.out.printf("\n");
  }
  static void initialize(Integer[]a){
    for(int i=0;i<a.length;i++)
      a[i]=0;
  }
  static void initialize(ArrayList<Integer>a){
    for(int i=0;i<a.size();i++)
      a.set(i,0);
  }
  public static void main(String[]args){
    initialize(arr1);
    print(arr1);
    Integer[] arr2=new Integer[lim];
    initialize(arr2);
    print(arr2);
    for(int i = 0 ; i < 3 ; i ++)
        arr3.add(3);
    print(arr3);
    arr3.set(1,5);
    print(arr3);
    arr3.remove(arr3.size()-1);
    print(arr3);
    arr3.add(1,10);
    print(arr3);
    arr3.remove(1);
    print(arr3);
  }
}