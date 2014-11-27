#include <iostream>
#include <algorithm>
typedef unsigned long long u64;
struct Counter{
    u64 cnt[11];
    Counter(){
        std::fill(cnt, cnt+11, 0);
        return;
    }
    static Counter from(u64 a, std::size_t i=0){
        Counter res;
        for(std::size_t j=0;j<i || a;j++){
            res.cnt[a%10]++;
            a/=10;
        }
        res.cnt[10]=1;
        return res;
    }
};
Counter operator*(const u64 &a, const Counter &b){
    Counter res;
    for(std::size_t i=0;i<11;i++) res.cnt[i]=a*b.cnt[i];
    return res;
}
Counter &operator+=(Counter &a, const Counter &b){
    for(std::size_t i=0;i<11;i++) a.cnt[i]+=b.cnt[i];
    return a;
}
Counter operator+(const Counter &a, const Counter &b){
    Counter res;
    for(std::size_t i=0;i<11;i++) res.cnt[i]=a.cnt[i]+b.cnt[i];
    return res;
}
struct Counters{
    Counter cnt[28];
};
Counters do28(u64 begin, u64 end){
    Counters res;
    if(begin==end) return res;
    u64 e10=end/10;
    if(begin/10!=e10){
        while(begin%10!=0){
            res.cnt[begin%28]+=Counter::from(begin);
            ++begin;
        }
        u64 b10=begin/10;
        Counters c=do28(b10, e10);
        for(std::size_t i=0;i<28;i++){
            for(std::size_t j=0;j<10;j++){
                std::size_t x=(10*i+j)%28;
                Counter next=c.cnt[i];
                next.cnt[j]+=c.cnt[i].cnt[10];
                res.cnt[x]+=next;
            }
        }
        begin=e10*10;
    }
    while(begin!=end){
        res.cnt[begin%28]+=Counter::from(begin);
        ++begin;
    }
    return res;
}
int main(){
    u64 a, b;
    std::cin>>a>>b;
    Counters cnt=do28(a, b+1);
    Counter res;
    for(std::size_t i=0;i<28;i++){
        if(i%4==0 || i%7==0){
            res+=cnt.cnt[i];
        }
    }
    for(std::size_t i=0;i<10;i++){
        if(i) std::cout<<' ';
        std::cout<<res.cnt[i];
    }
    std::cout<<'\n';
    return 0;
}
