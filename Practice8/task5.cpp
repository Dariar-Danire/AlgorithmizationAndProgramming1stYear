class IntSharedPointer {
private:
    int* ref;
    int* point;
    void decreaseRefs() {
        (*ref)--;
        if (*ref == 0) {
            delete point;
            delete ref;
        }
    }
    void copyRefs(const IntSharedPointer& val) {
        point = val.point;
        ref = val.ref;
        (*ref)++;
    }
    
public:
    IntSharedPointer(int* pointer) {
        ref = new int{1};
        point = pointer;
    }
    IntSharedPointer(IntSharedPointer& val) {
        copyRefs(val);
    }
    ~IntSharedPointer() {
        decreaseRefs();
    }
    int& operator*() {
        return *point;
    }
    IntSharedPointer& operator=(const IntSharedPointer& val) {
        if (this == &val) {
            return *this;
        }
        decreaseRefs();
        copyRefs(val);
        return *this;
    }
};
