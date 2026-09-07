#pragma once

#include <glad/glad.h>

class VBO {

public:
    unsigned int ID;
    VBO(float* vertices, GLsizeiptr size) {
        glGenBuffers(1, &ID);
        glBindBuffer(GL_ARRAY_BUFFER, ID);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    ~VBO() {
        glDeleteBuffers(1, &ID);
    }

    void Bind() {
        glBindBuffer(GL_ARRAY_BUFFER, ID);
    }
    void Unbind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};