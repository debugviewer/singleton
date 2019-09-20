#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <mutex>
#include <stdlib.h> // for atexit

#define USE_ATEXIT 1

template<class T>
class Singleton {
public:
	static T* getInstance() {
		static std::once_flag _oc;
		std::call_once(_oc, [&] {
			m_instance = new T();
		#if USE_ATEXIT
			atexit(Singleton<T>::destroy);			
		#else
			static Clean _clean;
		#endif
		});

		return m_instance;
	}
protected:
private:
#if USE_ATEXIT
	static void destroy() {
		if (m_instance) {
			delete m_instance;
			m_instance = nullptr;
		}
	}
#else
	class Clean {
	public:
		~Clean() {
			if (m_instance) {
				delete m_instance;
				m_instance = nullptr;
			}
		}
	};
#endif
	static T* m_instance;
};

template<class T>
T* Singleton<T>::m_instance(nullptr);

#endif // !__SINGLETON_H__
