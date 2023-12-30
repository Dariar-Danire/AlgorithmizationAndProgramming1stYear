Any::~Any() {
    if (type == Type::VECTOR_ANY_PTR) {
        auto ptr = static_cast<std::vector<Any*>*>(data);
        for (auto& it : *ptr) {
            delete it;
        }
        delete ptr;
    }
    else if (type == Type::INT) {
        int* ptr = static_cast<int*>(data);
        delete ptr;
    }
    else if (type == Type::DOUBLE) {
        double* ptr = static_cast<double*>(data);
        delete ptr;
    }
    else if (type == Type::STRING) {
        std::string* ptr = static_cast<std::string*>(data);
        delete ptr;
    }
}

Any::Any(int* data) {
    this->data = data;
    this->type = Type::INT;
}

Any::Any(double* data) {
    this->data = data;
    this->type = Type::DOUBLE;
}

Any::Any(std::string* data) {
    this->data = data;
    this->type = Type::STRING;
}

Any::Any(std::vector<Any*>* data) {
    this->data = data;
    this->type = Type::VECTOR_ANY_PTR;
}

Any::operator int() {
    if (type != Type::INT) {
        throw "";
    }

    return *static_cast<int*>(data);
}

Any::operator double() {
    if (type != Type::DOUBLE) {
        throw "";
    }

    return *static_cast<double*>(data);
}

Any::operator std::string() {
    if (type != Type::STRING) {
        throw "";
    }

    return *static_cast<std::string*>(data);
}

Any::operator std::vector<Any*>* () {
    if (type != Type::VECTOR_ANY_PTR) {
        throw "";
    }

    return static_cast<std::vector<Any*>*>(data);
}

std::ostream& operator<<(std::ostream& out, const Any& val) {
    if (val.type == Any::Type::VECTOR_ANY_PTR) {
        auto ptr = static_cast<std::vector<Any*>*>(val.data);
        for (auto& it : *ptr) {
            out << *it << " ";
        }
    }
    else if (val.type == Any::Type::INT) {
        int* true_pointer = static_cast<int*>(val.data);
        out << *true_pointer;
    }
    else if (val.type == Any::Type::DOUBLE) {
        double* true_pointer = static_cast<double*>(val.data);
        out << *true_pointer;
    }
    else if (val.type == Any::Type::STRING) {
        std::string* true_pointer = static_cast<std::string*>(val.data);
        out << *true_pointer;
    }
    return out;
}
