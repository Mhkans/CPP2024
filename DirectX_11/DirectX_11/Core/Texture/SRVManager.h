#pragma once
class SRVManager
{
	SRVManager();
	~SRVManager();
public:
	static void Create() {
		if (_instance == nullptr) {
			_instance = new SRVManager();
		}
	}
	static void Delete() {
		delete _instance;
	}
	static SRVManager* Instance() {
		return _instance;
	}
	shared_ptr<ShaderResourceView> AddSRV(wstring path);

private:
	static SRVManager* _instance;
	unordered_map<wstring, shared_ptr<ShaderResourceView>> _srvTable;
};

