#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
private:
    // ده الـ Pointer المزعج، خبّيناه هنا عشان محدش يشوفه
    GLFWwindow* m_window;

    // دالة الطوارئ (خليناها static عشان تشتغل مع مكتبة C القديمة بتاعت GLFW)
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        glViewport(0, 0, width, height);
    }

public:
    // الـ Constructor: ده الكود اللي هيشتغل أوتوماتيك أول ما تكتب اسم الكلاس
    Window(int width, int height, const char* title) {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (m_window == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
        }
        else {
            glfwMakeContextCurrent(m_window);
            glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
        }

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    }

    // الـ Destructor: بينضف الميموري لوحده لما البرنامج يقفل
    ~Window() {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    // دالة بتسأل الشاشة المفروض تقفل ولا لأ
    bool ShouldClose() {
        return glfwWindowShouldClose(m_window);
    }

    // دالة بتحدث الشاشة (بتبدل البافرز وتسمع الكيبورد)
    void Update() {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    // دالة بتنضف الشاشة باللون اللي تختاره
    void Clear(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
};