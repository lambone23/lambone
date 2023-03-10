#pragma once
#include "CResource.h"

namespace yha
{
	class CResources
	{
	public:
		template <typename T>
		static T* FnFind(const std::wstring& Key)
		{
			// 리소스맵에서 데이터를 탐색한다.
			// 데이터가 있다면 해당데이터를 반환
			// 데이터가 없다면 end를 반환
			std::map<std::wstring, CResource*>::iterator Iter = mResources.find(Key);

			// 찾고자 하는 데이터가 존재한다면
			// 해당타입으로 형변환하여 반환
			if (Iter != mResources.end())
			{
				return dynamic_cast<T*>(Iter->second);
			}

			//데이터 없다면 널을 반환
			return nullptr;
		}

		template <typename T>
		static T* FnLoad(const std::wstring& Key, const std::wstring& Path)
		{
			// 키값으로 탐색
			T* Resource = CResources::FnFind<T>(Key);
			if (Resource != nullptr)
			{
				return Resource;
			}

			// 해당 리소스가 없다면
			Resource = new T();
			if (FAILED(Resource->FnLoad(Path)))
			{
				assert(false);
				return nullptr;
			}

			Resource->FnSetKey(Key);
			Resource->FnSetPath(Path);
			mResources.insert(std::make_pair(Key, Resource));

			return dynamic_cast<T*>(Resource);
		}

		template <typename T>
		static void FnInsert(const std::wstring& Key, T* Resource)
		{
			mResources.insert(std::make_pair(Key, Resource));
		}

		static void Release()
		{
			for (auto pair : mResources)
			{
				delete pair.second;
				pair.second = nullptr;
			}
		}

	private:
		static std::map<std::wstring, CResource*> mResources;
	};
}

