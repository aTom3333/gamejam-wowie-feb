#ifndef SCOPEGUARD_HPP
#define SCOPEGUARD_HPP

template<typename Func>
class ScopeGuard
{
public:
    ScopeGuard(Func&& func): func_{std::forward<Func>(func)} {}
    ~ScopeGuard() { func_(); }
private:
    Func func_;
};

#endif // SCOPEGUARD_HPP
