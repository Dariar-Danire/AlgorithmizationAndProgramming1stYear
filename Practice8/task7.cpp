class GreaterAdapter: public IComparator{
    using func = void (*)(int a, int b, bool& verd);
    func comp;
public:
    GreaterAdapter(func comp): comp(comp){
    }

    bool compare(int fir, int sec) const override {
        bool result;
        comp(fir, sec, result);
        return result;
    }
};

class KeyFuncLessAdapter: public IComparator{
    using func = double (*)(int value);
    func function_k;
public:
    KeyFuncLessAdapter(func function_k): function_k(function_k){
    }

    bool compare(int fir, int sec) const override {
        return function_k(fir) < function_k(sec);
    }
};
