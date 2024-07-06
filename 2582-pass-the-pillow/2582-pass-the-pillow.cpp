// class Solution {
// public:
//     int passThePillow(int n, int time) {
//         int flag=0;
//         int i=1;
//         int t=time;
//         while(t){
//             if(i==n)flag=!flag;
//             else if(i==1 && t!=time)flag=!flag;

//             if(flag==0){
//                 i++;
                
//             }
//             else{
//                 i--;
                
//             }
//             t--;
//         }
//         return i;
//     }
// };

//there are n then hopes will be n-1 in one round 
//ie if time =7 n=4 and there will be 3 hopes no. of rounds =7/3=2 
//if even round it stat from left if ood round it start from right
//the remaining hopes in 7 seconds is 7-(2*3) or 7%3 =1 ie remainder

class Solution {
public:
    int passThePillow(int n, int time) {
int round=time/(n-1);
int remhope=time%(n-1);
int ans=0;
if(round%2==0){
    ans=1+remhope;
}
else{
    ans=n-remhope;
}

return ans;
   }
};
