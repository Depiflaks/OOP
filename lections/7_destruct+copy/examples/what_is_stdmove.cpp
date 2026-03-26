
class X {
    std::vector<char> data;
    public:
    X() = default;
    std::vector<char> const& data() const& {
        return data;
    }
    std::vector<char>&& data()&& {
        return std::move(data);
    }
}