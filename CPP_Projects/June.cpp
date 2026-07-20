#include<iostream>
#include<string>

bool matchPart(const std::string& pat,const std::string& s,int start){
    for(int i=0;i<(int)pat.size();i++){
        if(pat[i]!='?'&&pat[i]!=s[start+i]){
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string pattern;
    std::cin>>pattern;

    int pos=pattern.find('*');
    std::string pre=pattern.substr(0,pos);
    std::string suf=pattern.substr(pos+1);

    int n;
    std::cin>>n;

    std::string ans;

    while(n--){
        std::string s;
        std::cin>>s;

        bool ok=true;

        if((int)s.size()<(int)pre.size()+(int)suf.size()){
            ok=false;
        }else{
            if(!matchPart(pre,s,0))ok=false;
            if(ok&&!matchPart(suf,s,(int)s.size()-(int)suf.size())){
                ok=false;
            }
        }
        ans+=ok?'Y':'N';
    }
    std::cout<<ans<<"\n";

    return 0;
}