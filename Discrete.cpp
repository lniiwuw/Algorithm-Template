template<typename T>
class Discrete {
private:
	std::vector<T> vec;
public:
	Discrete() {}
	Discrete(std::vector<T> &v) : vec(v) {}
	void add(T x) { vec.push_back(x); }
    void add(std::vector<T> v) { vec.insert(vec.end(), v.begin(), v.end()); }
	void work() {
		sort(vec.begin(), vec.end());
		typename std::vector<T>::iterator it = std::unique(vec.begin(), vec.end());
		if (it != vec.end()) vec.erase(it, vec.end());
	}
	int getId(T x) {
		return std::lower_bound(vec.begin(), vec.end(), x) - vec.begin();
	}
	int size() { return vec.size(); }
	T operator[] (int id) {
		assert(id < vec.size());
		return vec[id];
	}
};
