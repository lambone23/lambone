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
			// ���ҽ��ʿ��� �����͸� Ž���Ѵ�.
			// �����Ͱ� �ִٸ� �ش絥���͸� ��ȯ
			// �����Ͱ� ���ٸ� end�� ��ȯ
			std::map<std::wstring, CResource*>::iterator Iter = mResources.find(Key);

			// ã���� �ϴ� �����Ͱ� �����Ѵٸ�
			// �ش�Ÿ������ ����ȯ�Ͽ� ��ȯ
			if (Iter != mResources.end())
			{
				return dynamic_cast<T*>(Iter->second);
			}

			//������ ���ٸ� ���� ��ȯ
			//return nullptr;
			return NULL;
		}

		template <typename T>
		static T* FnLoad(const std::wstring& Key, const std::wstring& Path)
		{
			// Ű������ Ž��
			T* Resource = CResources::FnFind<T>(Key);
			//if (Resource != nullptr)
			if (Resource != NULL)
			{
				return Resource;
			}

			// �ش� ���ҽ��� ���ٸ�
			Resource = new T();
			if (FAILED(Resource->FnLoad(Path)))
			{
				assert(false);
				//return nullptr;
				return NULL;
			}

			Resource->FnSetKey(Key);
			Resource->FnSetPath(Path);
			mResources.insert(std::make_pair(Key, Resource));

			return dynamic_cast<T*>(Resource);
		}

		static void Release()
		{
			for (auto pair : mResources)
			{
				delete pair.second;
				//pair.second = nullptr;
				pair.second = NULL;
			}
		}

	private:
		static std::map<std::wstring, CResource*> mResources;
	};
}
