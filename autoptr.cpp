//from scott myers

#include <iostream>

template<typename T>
class autoptr {
public:
	explicit autoptr(T *p = nullptr) : pointee(p) {}
	
	template<class U>
	autoptr(autoptr<U>& rhs) : pointee(rhs.release()) {}
	
	~autoptr() { delete pointee; }
	
	template<class U>
	autoptr<T>& operator=(autoptr<U>& rhs) {
		if (this != &rhs) reset(rhs.release());
		return *this;
	}
	T& operator*() const { return *pointee; }
	T* operator->() const { return pointee; }
	T* get() const { return pointee; }
	
	T* release() {
		T *oldPointee = pointee;
		pointee = 0;
		return oldPointee;
	}
	
	void reset(T *p = nullptr) {
		if (pointee != p) {
			delete pointee;
			pointee = p;
		}
	}
private:
	T *pointee;
	//???
	//template<class U> friend class autoptr<U>;
};