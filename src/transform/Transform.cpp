#include "transform/Transform.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/quaternion_transform.hpp"
#include "glm/gtx/string_cast.hpp"

void transform::Transform::addRotation(const float& rotationRadians, const glm::vec3& axis)
{
    initialize();
    this->transformMatrix = glm::rotate(this->transformMatrix, rotationRadians, axis);
}

void transform::Transform::addTranslation(const glm::vec3& translation)
{
    initialize();
    this->transformMatrix = glm::translate(this->transformMatrix, translation);
}

void transform::Transform::addScale(const glm::vec3& zoom)
{
    initialize();
    this->transformMatrix = glm::scale(this->transformMatrix, zoom);
}

void transform::Transform::initialize()
{
    if (! isInitialized())
    {
        this->transformMatrix = glm::mat4(1.0f);
        this->initialized = true;
    }
}

glm::mat4 transform::Transform::getMatrix()
{
    initialize();
    return this->transformMatrix;
}