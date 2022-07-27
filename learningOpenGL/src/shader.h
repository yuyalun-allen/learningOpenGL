#pragma once

#include <glad\glad.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class Shader {
public:
	Shader(const char* vsPath, const char* fsPath);
	void use() { glUseProgram(ID); }

    void setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    // ------------------------------------------------------------------------
    void setInt(const std::string& name, int value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, float value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setMat4(const std::string& name, glm::mat4 value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
    }

private:
	unsigned int ID;
    void checkCompileErrors(unsigned int shader, std::string type);
};
