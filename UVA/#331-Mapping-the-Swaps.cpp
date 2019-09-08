#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int> p;
int n, res = 0;
std::vector<std::vector<int>> perms(static_cast<std::size_t>(std::pow(n, n)));

void init(int rem, std::vector<int>& curr) {
    if(rem == 0) {
        perms.push_back(curr);
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(!curr.empty() && curr[curr.size() - 1] == i) continue;
        curr.push_back(i);
        init(rem - 1, curr);
        curr.pop_back();
    }
}

template<class Iter, class Cmp = std::less<int>>
unsigned int merge(Iter begin, Iter mid, Iter end, const Cmp& cmp = Cmp())
{
    auto lhs_len = std::distance(begin,mid);
    unsigned int count = 0;

    std::vector<int> sorted;

    Iter lhs = begin, rhs = mid;
    while (lhs != mid && rhs != end) {
        if (cmp(*lhs,*rhs) || !cmp(*rhs,*lhs)) {
            sorted.emplace_back(*lhs++);
        }
        else {
            sorted.emplace_back(*rhs++);
            count += (lhs_len - std::distance(begin,lhs));
        }
    }

    while (lhs != mid) {
        sorted.emplace_back(*lhs++);
    }
    while (rhs != end) {
        sorted.emplace_back(*rhs++);
    }

    std::copy(sorted.begin(), sorted.end(), begin);

    return count;
}

template<class Iter, class Cmp = std::less<int>>
unsigned int mergesort(Iter begin, Iter end, const Cmp& cmp = Cmp())
{
    auto len = std::distance(begin, end);
    if (len < 2)
        return 0;

    Iter mid = std::next(begin, len/2);

    return mergesort(begin, mid, cmp) +
           mergesort(mid, end, cmp) +
           merge(begin, mid, end, cmp);
}


bool is_sorted(std::vector<int> &pd) {
    for(int i = 1; i < pd.size(); i++) {
        if(pd[i] < pd[i - 1]) return false;
    }
    return true;
}

void sol(std::vector<int> cp, std::vector<int>& prm) {
    for(int sw : prm) {
        std::swap(cp[sw], cp[sw + 1]);
    }
    if(is_sorted(cp)) ++res;
}

int main() {
//    auto t1 = std::chrono::high_resolution_clock::now();
    std::size_t set_num = 0;
    bool first_time = true;
	while(std::cin >> n && n != 0) {
	    if(!first_time) {
            std::cout << '\n';
        } else first_time = false;
	    res = 0;
        p.clear();
        p.resize(n);
        for(int &e : p) std::cin >> e;
        auto cpp = p;
        int s = mergesort(cpp.begin(), cpp.end());
        if(!s) {
            std::cout << "0\n";
            continue;
        }
        std::vector<int> tm;
        perms.clear();
        init(s, tm);
        for(auto &perm : perms) {
            sol(p, perm);
        }
        std::cout << "There are " << res << " swap maps for input data set " << ++set_num << ".";
    }

//    auto t2 = std::chrono::high_resolution_clock::now();
//	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();

    return 0;
}
