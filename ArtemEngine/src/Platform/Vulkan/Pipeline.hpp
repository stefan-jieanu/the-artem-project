#pragma once

namespace Engine
{
    
class Pipeline 
{
public:
    Pipeline(const std::string& vertFilepath, const std::string& fragFilepath);

private:
    static std::vector<char> readFile(const std::string& filepath);

    void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
};

} // namespace Engine
