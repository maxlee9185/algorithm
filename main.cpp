#define _CRT_SECURE_NO_WARNINGS
#if 0
//1085 직사각형에서 탈출
#include <iostream>
#define MIN(x,y) (((x)>(y))?(y):(x))
using namespace std;

int x,y,w,h;
int ans1, ans2;
int main() {
    scanf("%d %d %d %d",&x,&y,&w,&h);
    ans1=MIN(x,y);
    ans2=MIN(w-x,h-y);

    printf("%d",MIN(ans1,ans2));
    return 0;
}
#endif

#if 1
#include <iostream>
using namespace std;

int w,h,x,y,p;
int ans;
bool isInSquare(int xx, int yy)
{
    if (xx>=x && xx<=x+w && yy>=y && yy<=y+h) return true;
    return false;
}
int distance(int a, int b, int c, int d)
{
    return ( (a-c)*(a-c) + (b-d)*(b-d) );
}
bool isInCircle(int xx, int yy){
    if( distance(x,y+ h/2, xx, yy ) <= ( (h/2)*(h/2) ) ) return true;
    if( distance(x+w,y+h/2,xx,yy) <= ( (h/2)*(h/2) )) return true;
    return false;
}

int main(){

    scanf("%d %d %d %d %d",&w,&h,&x,&y,&p);

    for(int i=0;i<p;i++){
        int r,c;
        scanf("%d %d",&r,&c);
        if(isInSquare(r,c)) ans++;
        else if(isInCircle(r,c)) ans++;
    }
    printf("%d\n",ans);
}
#endif
