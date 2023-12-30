class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << std::endl;
    }
};

class StringPrintStrategy : public PrintStrategy {
    std::string save = "";
    int cnt = 1;
public:
    void print(const Document& document) override {
        save += "--- doc " + std::to_string(cnt) + " ---\n" + document.get() + "\n";
        cnt++;
    }
    std::string getPrintedDocuments() const {
        return save;
    }
};

class MockPrintStrategy : public PrintStrategy {
    int cnt = 0;
public:
    void print(const Document& document) override {
        cnt++;
    }
    int getPrintedDocumentsCount() const {
        return cnt;
    }
};
