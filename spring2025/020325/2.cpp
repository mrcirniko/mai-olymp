#include <iostream>
#include <vector>


void swap(int index, int i, std::vector<long long int>& s){
    int sw = s[index];
    s[index] = s[i];
    s[i] = sw;
}

int check(std::vector<long long int>& s, std::vector<long long int>& c, int n){
    long long int last = 0;
    for(int i = 0; i < n; ++i){
       long long int dif = c[i] - last;
       if(dif >= 0){
           last = s[i] - dif;
           if(last < 0){
               return i;
           }
       }
       else{
           last = s[i];
       }
    }
    return -1;
}


int main(){
    int n;
    std::cin >> n;
    std::vector<long long int> s(n);
    for(int i = 0; i < n; ++i){
        std::cin >> s[i];
    }
    std::vector<long long int> c(n);
    for(int i = 0; i < n; ++i){
        std::cin >> c[i];
    }
    
    int index = check(s, c, n);
    if(index == -1){
       std::cout << "Yes" << std::endl;
       return 0;
    }
    for(int j = n - 1; j >= 0; --j){
        for(int i = 0; i < n; ++i){
            swap(j, i, s);
            int answer = check(s, c, n);
            if(answer == -1){
                std::cout << "Yes" << std::endl;
                return 0;
            }
            swap(j, i, s);
        }
    }
    std::cout << "No" << std::endl;
}
