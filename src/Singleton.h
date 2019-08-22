#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <mutex>

template<class T>
class Singleton {
public:
	static T* getInstance() {
		static std::once_flag _oc;
		std::call_once(_oc, [&] {
			m_instance = new T();
			static Clean _clean;
		});

		return m_instance;
	}
protected:
private:
	class Clean {
	public:
		~Clean() {
			if (m_instance) {
				delete m_instance;
				m_instance = nullptr;
			}
		}
	};

	static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance(nullptr);

#endif // !__SINGLETON_H__
