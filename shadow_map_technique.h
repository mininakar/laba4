#pragma once
#define	SHADOW_MAP_TECHNIQUE_H
#include "technique.h"
#include <glm/glm.hpp>	//#include "math_3d.h" - vector
#include "math_3d.h"

class ShadowMapTechnique : public Technique {

public:
    ShadowMapTechnique();
    virtual bool Init();
    void SetWVP(const glm::mat4& WVP);
    void SetTextureUnit(unsigned int TextureUnit);

private:

    GLuint m_WVPLocation;
    GLuint m_textureLocation;
};
