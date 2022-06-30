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

#if 0
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

#if 1
#include <iostream>
using namespace std;
#define MAXN (50+2)
int T, N,ans;
int x1,x2,y1,y2;
struct Circle{
    int x,y,r;
}circle[MAXN];
int len, dist;
void solve(){
    ans=0;
    for(int i=0;i<N;i++){
        if( (circle[i].x-x1)*(circle[i].x-x1) + (circle[i].y-y1)*(circle[i].y-y1) <circle[i].r*circle[i].r){
            if( (circle[i].x-x2)*(circle[i].x-x2) + (circle[i].y-y2)*(circle[i].y-y2) > circle[i].r * circle[i].r ) ans++;
        }
        if( (circle[i].x-x1)*(circle[i].x-x1) + (circle[i].y-y1)*(circle[i].y-y1) >circle[i].r*circle[i].r){
            if( (circle[i].x-x2)*(circle[i].x-x2) + (circle[i].y-y2)*(circle[i].y-y2) < circle[i].r * circle[i].r ) ans++;
        }
    }


}
int main(){
    scanf("%d",&T);
    for(int tc=0;tc<T;tc++){
        scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d %d %d",&circle[i].x,&circle[i].y,&circle[i].r);
        }
        solve();
        printf("%d\n",ans);
    }
    return 0;
}
#endif
