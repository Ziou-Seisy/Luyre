export module FileID;
import <string>;
import <unordered_map>;
import <filesystem>;

namespace fs = std::filesystem;
class FileIdMapper {
    std::unordered_map<std::string, size_t> pathToId;
    std::vector<std::string> idToPath;
    size_t nextId = 0;
public:
    size_t getID(const std::string &pathStr) {
        auto key = fs::canonical(pathStr).string();
        auto it = pathToId.find(key);
        if (it != pathToId.end()) return it->second;
        size_t id = nextId++;
        pathToId[key] = id;
        idToPath.push_back(key);
        return id;
    }
    std::string getName(size_t id) const {
        return (id < idToPath.size()) ? idToPath[id] : "";
    }
};
export FileIdMapper fileIdMapper;