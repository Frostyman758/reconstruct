#ifndef COMMON_H_
#define COMMON_H_

// Common constant buffer bindings shared across shaders. The REGISTERMAP macro is
// defined in the platform-specific shader headers (see DgShaderDefine*.h) and
// expands to the appropriate HLSL/GLSL construct for declaring constant buffers.
REGISTERMAP(PSScene,    g_psScene,    PS_REGISTER(SCENE));
REGISTERMAP(PSObject,   g_psObject,   PS_REGISTER(OBJECT));
REGISTERMAP(PSLight,    g_psLight,    PS_REGISTER(LIGHT));
REGISTERMAP(PSMaterial, g_psMaterial, PS_REGISTER(MATERIAL));
REGISTERMAP(PSWork,     g_psWork,     PS_REGISTER(WORK));
REGISTERMAP(PSSystem,   g_psSystem,   PS_REGISTER(SYSTEM));

#ifndef USE_CONSTANTBUFFER
REGISTERMAP(PSTiling,   g_psTiling,   PS_REGISTER(TILING));
#endif // USE_CONSTANTBUFFER

inline float3 GetEyePosition()
{
    return g_psScene.m_eyepos.xyz;
}

#endif // COMMON_H_
