#pragma once

#include "Initializable.h"
#include "PCH.h"

namespace transform {
    class Transform : Initializable
    {
    private:
        glm::mat4 transformMatrix;
        void initialize();
    public:
        void addRotation(const float& rotationRadians, const glm::vec3& axis);
        void addTranslation(const glm::vec3& translation);
        void addScale(const glm::vec3& zoom);
        glm::mat4 getMatrix();
    };
}
