class Label : public Leaf {
    std::string info;
public:
    Label(const std::string& info) : info(info) {
    }

    Canvas render() override {
        Canvas c;
        c.draw(info);
        return c;
    }

    std::string click(int x, int y) override {
        return "Label(" + info + ")";
    }
};

class CheckBox : public Leaf {
    std::string info;
    bool flag;
public:
    CheckBox(const std::string& txt, const bool status) : info(txt), flag(status) {
    }

    Canvas render() override {
        Canvas c;
        c.draw("[" + std::string(flag ? "x" : " ") + "] " + info);
        return c;
    }

    std::string click(int x, int y) override {
        return "CheckBox(" + info + ")";
    }
};

class VLayout : public Composite {
public:
    Canvas render() override {
        Canvas c;

        for (auto i : components) {
            Canvas t = i->render();
            c.draw(t, 0, c.height() == 0 ? 0 : c.height() + 1);
        }

        return c;
    }

    std::string click(int x, int y) override {
        int cnt_x = 0;
        int cnt_y = 0;

        for (auto i : components) {
            Canvas t = i->render();
            cnt_x = t.width();
            cnt_y += t.height();

            if (cnt_y > y) {
                if (cnt_x > x) {
                    return i->click(x, y - (cnt_y - t.height()));
                }
                else return "Empty";
            }

            cnt_y += 1;
            if (cnt_y > y) return "Empty";
        }
        return "Empty";
    }
};
