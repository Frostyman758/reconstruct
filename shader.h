/** @file system/Gr/Dg/shader/shader.h
 */
// Encoding: SJIS
// ï¿½ï¿½ï¿½ÓFHLSLï¿½ï¿½ï¿½Rï¿½ï¿½ï¿½pï¿½Cï¿½ï¿½ï¿½Åï¿½ï¿½é½ï¿½ßAï¿½ï¿½ï¿½Ìtï¿½@ï¿½Cï¿½ï¿½ï¿½ï¿½SJISï¿½ÅÈï¿½ï¿½ï¿½ï¿½ÎÈï¿½ï¿½Üï¿½ï¿½ï¿½
//       ï¿½ï¿½ï¿½Ìï¿½ï¿½ßAdoxygenï¿½ï¿½ï¿½pï¿½[ï¿½Xï¿½ï¿½ï¿½ï¿½ï¿½Æï¿½ï¿½{ï¿½êªï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÉÈï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ÌÅA
//       ï¿½hï¿½Lï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½gï¿½ï¿½UTF8ï¿½ÌÊÌtï¿½@ï¿½Cï¿½ï¿½ï¿½Éï¿½ï¿½ï¿½ï¿½Üï¿½ï¿½F shader_doc.h
//
//        ï¿½Öï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÍÊÌêï¿½Éï¿½ï¿½ï¿½ï¿½Æï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½á¢ï¿½ï¿½ï¿½ï¿½ï¿½ÈÌÅAï¿½Æè ï¿½ï¿½ï¿½ï¿½ï¿½A
//        ï¿½ï¿½ï¿½Ìtï¿½@ï¿½Cï¿½ï¿½ï¿½Åpï¿½ï¿½ï¿½Åï¿½ï¿½ï¿½ï¿½Üï¿½ï¿½B
//
//		 ShaderPreprocessorï¿½ï¿½ï¿½gï¿½ï¿½ï¿½ï¿½ï¿½ÆÅABOMï¿½ï¿½ï¿½ï¿½ï¿½é±ï¿½Æï¿½ï¿½Åï¿½ï¿½ï¿½ï¿½ÌÅA
//       ï¿½ï¿½ï¿½Ýï¿½HSLSï¿½tï¿½@ï¿½Cï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½×ï¿½.shdrï¿½tï¿½@ï¿½Cï¿½ï¿½ï¿½ÉÚsï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½AUTF8ï¿½ÉÏXï¿½ï¿½ï¿½Üï¿½ï¿½B

#include "DgShaderDefine.h"

#ifndef _SHADER_H_
#define _SHADER_H_

#ifdef F_TARGET_WIN32
#ifdef DG_SHADER_GEN_DX11
#define F_TARGET_WINDX11
#endif
#ifdef DG_SHADER_GEN_DX9
#define F_TARGET_WINDX9
#endif
#endif

#ifdef F_TARGET_XBOX360
#pragma warning( disable : 3596 )	// ï¿½gï¿½pï¿½ï¿½ï¿½Äï¿½ï¿½Èï¿½ï¿½Zï¿½}ï¿½ï¿½ï¿½eï¿½Bï¿½Nï¿½Xï¿½ï¿½ï¿½ï¿½ï¿½mï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ÌÅ}ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½
#endif

#ifdef F_TARGET_PS4
// D5203 ï¿½ï¿½ï¿½ï¿½ï¿½Ìï¿½ï¿½Qï¿½ÆÏï¿½ï¿½xï¿½ï¿½
// D2201 ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½NULLï¿½ï¿½ï¿½ï¿½ï¿½ð³ï¿½ï¿½ï¿½ï¿½Üï¿½ï¿½ï¿½
// D5609 ï¿½ï¿½ï¿½Îï¿½ï¿½Ïï¿½ï¿½ï¿½ï¿½xï¿½ÌØï¿½ï¿½ã°ï¿½xï¿½ï¿½(half->float)
#pragma warning (disable:5203 2201 5609)
#endif

// --------------------------------------------- Common
#define HALF_MIN	(-65504.0)
#define HALF_MAX	(65504.0)

// --------------------------------------------- Xbox 360
#ifdef F_TARGET_XBOX360
// Aspect ï¿½ï¿½ï¿½ï¿½ï¿½lï¿½ï¿½ï¿½Èï¿½ï¿½ï¿½ï¿½ÎA1152x672 \ï¿½Æï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define GBUFFER_WIDTH		(984.0)
#define GBUFFER_HEIGHT		(720.0)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)
// 360ï¿½Åï¿½COLORï¿½Ìï¿½ï¿½ÔÍá¤
#define ResolveEndian(color) color.abgr

#define h4tex1D(_s, _uv)		tex1D(_s, _uv)
#define h4tex2D(_s, _uv)		tex2D(_s, _uv)
#define h4tex3D(_s, _uv)		tex3D(_s, _uv)
#define h4tex2Dlod(_s, _uv)		tex2Dlod(_s, _uv)
#define h4tex2Dproj(_s, _uv)	tex2Dproj(_s, _uv)

#define discard					clip(-1)

#endif	// ifdef F_TARGET_XBOX360

// --------------------------------------------- XboxOne
#ifdef F_TARGET_XBOXONE
#define ResolveEndian(color) color.rgba

#define GBUFFER_WIDTH		(1600.0)
#define GBUFFER_HEIGHT		(900.0)
//#define GBUFFER_WIDTH		(1920.0)
//#define GBUFFER_HEIGHT	(1080.0)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)

#endif	// ifdef F_TARGET_XBOXONE


// --------------------------------------------- PlayStation3
#ifdef F_TARGET_PS3
#define MAX_CASCADE_BLOCKS	(4)
#define GBUFFER_WIDTH		(984.0)
#define GBUFFER_HEIGHT		(720.0)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)
#define ResolveEndian(color) color.rgba

#endif	// ifdef F_TARGET_PS3

// --------------------------------------------- PC, ï¿½ï¿½ï¿½Ìï¿½
#ifdef F_TARGET_WINDX9
#define ResolveEndian(color) color.rgba

#define GBUFFER_WIDTH		(1920)
#define GBUFFER_HEIGHT		(1080.0)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)

#define h4tex1D(_s, _uv)		((half4)tex1D(_s, _uv))
#define h4tex2D(_s, _uv)		((half4)tex2D(_s, _uv))
#define h4tex3D(_s, _uv)		((half4)tex3D(_s, _uv))
#define h4tex2Dlod(_s, _uv)		((half4)tex2Dlod(_s, _uv))
#define h4tex2Dproj(_s, _uv)	((half4)tex2Dproj(_s, _uv))
#endif // F_TARGET_WINDX9

#ifdef F_TARGET_WINDX11
#define ResolveEndian(color) color.rgba

#define GBUFFER_WIDTH		(1920)
#define GBUFFER_HEIGHT		(1080.0)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)

#define h4tex1D(_s, _uv)		((half4)tex1D(_s, _uv))
#define h4tex2D(_s, _uv)		((half4)tex2D(_s, _uv))
#define h4tex3D(_s, _uv)		((half4)tex3D(_s, _uv))
#define h4tex2Dlod(_s, _uv)		((half4)tex2Dlod(_s, _uv))
#define h4tex2Dproj(_s, _uv)	((half4)tex2Dproj(_s, _uv))

#pragma warning( disable : 4000 )

#endif // F_TARGET_WINDX11

// --------------------------------------------- PlayStation4
#ifdef F_TARGET_PS4
#define ResolveEndian(color) color.rgba

#define GBUFFER_WIDTH		(1920)
#define GBUFFER_HEIGHT		(1080)
#define GBUFFER_PIXELWIDTH	(1.0 / GBUFFER_WIDTH)
#define GBUFFER_PIXELHEIGHT	(1.0 / GBUFFER_HEIGHT)

#endif	// ifdef F_TARGET_PS4


//#ifndef F_TARGET_WIN32
#ifdef F_TARGET_PS3
#define GR_SHADER_ENABLE_OPTIMIZED_MOTION_BLUR
#endif
#ifdef F_TARGET_XBOX360
#define GR_SHADER_ENABLE_OPTIMIZED_MOTION_BLUR
#endif

#ifdef F_TARGET_WIN32
#define DG_SUPPORT_FLEXIBLE_VIEWPORT
#endif

// ï¿½tï¿½[ï¿½ï¿½ï¿½Xï¿½Nï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½Ìï¿½ï¿½Ìtï¿½Bï¿½ï¿½ï¿½^ï¿½ï¿½ï¿½ï¿½ï¿½ÆÅï¿½ï¿½Ìsï¿½Nï¿½Zï¿½ï¿½ï¿½Ìï¿½ï¿½iï¿½ï¿½ï¿½[ï¿½Vï¿½ï¿½ï¿½ï¿½ï¿½uï¿½ï¿½ï¿½[ï¿½pï¿½j
#ifdef GR_SHADER_ENABLE_OPTIMIZED_MOTION_BLUR
#define MAX_FILTER_WIDTH   (64)	// VelocityMapï¿½ï¿½1/4ï¿½Tï¿½Cï¿½Yï¿½ÈÌÅï¿½ï¿½ï¿½ï¿½Éï¿½ï¿½í¹ï¿½ï¿½1/4ï¿½Éï¿½ï¿½Äï¿½ï¿½ï¿½
#define MAX_FILTER_HEIGHT  (64)
#else
//#define MAX_FILTER_WIDTH   (512)
//#define MAX_FILTER_HEIGHT  (512)
#define MAX_FILTER_WIDTH   (64)
#define MAX_FILTER_HEIGHT  (64)
#endif

// ï¿½ï¿½ï¿½ï¿½ï¿½eï¿½Nï¿½Xï¿½`ï¿½ï¿½ï¿½ÌTï¿½Cï¿½Y
#define RANDOM_TEXTURE_SIZE (32.0)
#define INV_RANDOM_TEXTURE_SIZE (1.0 / 32.0)

// SRGB -> RGB ï¿½ï¿½
#define DECODING_GAMMA  (2.2)
// RGBï¿½ï¿½ï¿½Ôï¿½ï¿½ï¿½sRGBï¿½ï¿½ï¿½ÔÉï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ßDMacï¿½Ìêï¿½ï¿½0.55
#define ENCODING_GAMMA  (1.0/DECODING_GAMMA)

// ï¿½ï¿½ï¿½`ï¿½Ì[ï¿½xï¿½ï¿½ï¿½Âï¿½ï¿½ï¿½ï¿½ï¿½ï¿½é½ï¿½ßÉXï¿½Pï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½á¤
//#define DEBUG_Z_SCALE (15.0)

// ï¿½Fï¿½ï¿½ï¿½ï¿½ï¿½Ì}ï¿½gï¿½ï¿½ï¿½bï¿½Nï¿½Xï¿½ÍÇï¿½ï¿½Éï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½é©
#define COLOR_ROTATION    (g_psScene.m_shadowProjection)


//ï¿½tï¿½Hï¿½ï¿½ï¿½[ï¿½hï¿½ï¿½ï¿½fï¿½ï¿½ï¿½ï¿½ï¿½ð½sï¿½ï¿½ï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½ÉÎï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define ENABLE_NONDEFERRED_DISTANCE_FADE

// ----------------------------------------------------------------------- ï¿½Pï¿½xï¿½ÖW
//http://en.wikipedia.org/wiki/YCbCr
/// Vector to compute luminance. Follows the ITU-R BT.709 standard for HDTV
#define LUMINANCE_VECTOR  (half3(0.2125h, 0.7154h, 0.0721h))
// ITU-R BT.601 (NTSCï¿½Èï¿½)
//#define LUMINANCE_VECTOR  (half3(0.3h, 0.59h, 0.11h))

/// Scale for the luminance value, stored in alpha (used for tonemapping) 
#define MAX_LUMINANCE (32.0)
#if 0
/// HDRï¿½Gï¿½ï¿½ï¿½Rï¿½[ï¿½hï¿½p
#define HDR_LUM_SCALE ( 4.0h )
/// HDR_LUM_SCALE < g_psScene.m_exposureï¿½Éï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Pï¿½xï¿½Xï¿½Pï¿½[ï¿½ï¿½ï¿½@ï¿½ï¿½ DecodeHDRï¿½Íá¤!
#define IS_SMALL_LUM_SCALE
#else
// GrViewport.cppï¿½ï¿½c_lightingColorScale=4ï¿½ï¿½ï¿½ï¿½ï¿½`ï¿½ï¿½ï¿½ï¿½ï¿½ÄAï¿½Iï¿½oï¿½Éï¿½ï¿½ï¿½ï¿½Üï¿½
#define HDR_LUM_SCALE ( 16.0h )
#endif

#define USER_TEXCUBELOD	//ï¿½ï¿½ï¿½tï¿½ï¿½ï¿½Nï¿½Vï¿½ï¿½ï¿½ï¿½ï¿½vï¿½Zï¿½ï¿½texCUBElodï¿½ï¿½ï¿½gï¿½ï¿½
#ifdef USER_TEXCUBELOD
#define CUBEMAP_BIAS_MAX (5.0H)
#else
#define CUBEMAP_BIAS_MAX (8.0H)
#endif

#define LIGHTSCALE_DIFFUSE_TO_SPECULAR (3.1415926H)
#define FWLIGHT_INNER_RANGE (0.5)

#ifdef F_TARGET_PS3
#define DISABLE_SHADER_SKINNING	// SPUï¿½Xï¿½Lï¿½jï¿½ï¿½ï¿½Oï¿½ï¿½ï¿½Lï¿½ï¿½ï¿½Èêï¿½Éï¿½ï¿½_ï¿½Vï¿½Fï¿½[ï¿½_ï¿½[ï¿½ï¿½ï¿½ÌXï¿½Lï¿½jï¿½ï¿½ï¿½Oï¿½ï¿½ï¿½ï¿½ï¿½ð³ï¿½ï¿½Éï¿½ï¿½ï¿½
#endif


//#define ENABLE_GBUFF_SPEC_BLEND	//Gbufferï¿½oï¿½Íï¿½ï¿½ASpecularï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½Â\ï¿½`ï¿½ï¿½ï¿½ï¿½ï¿½lï¿½ï¿½ï¿½Éoï¿½Íï¿½ï¿½ï¿½ï¿½Bï¿½Ïï¿½ï¿½ï¿½ï¿½ï¿½Translucentï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½sï¿½\ï¿½ï¿½ 

// 
#ifdef F_TARGET_PS3
#define DEPTHTEXTURE_AS_PACKED_W
#endif

// -----------------------------------------------------------------------
// ï¿½ï¿½ï¿½fï¿½ï¿½ï¿½tï¿½Hï¿½[ï¿½}ï¿½bï¿½gï¿½ÖA
#if 1	// ï¿½ï¿½ï¿½fï¿½ï¿½ï¿½tï¿½Hï¿½[ï¿½}ï¿½bï¿½gï¿½ÏXï¿½ï¿½ï¿½sï¿½Èï¿½ï¿½ï¿½ï¿½ï¿½1ï¿½ï¿½
#ifdef F_TARGET_PS3
#define MODEL_TANGENT_IS_UNSIGNED_NORMALIZE	// ï¿½^ï¿½ï¿½ï¿½Wï¿½Fï¿½ï¿½ï¿½gï¿½ï¿½0~1ï¿½Åiï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Ìï¿½ n*2-1ï¿½Åï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Kï¿½vï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define CLONE_TANGENT_IS_UNSIGNED_NORMALIZE	// ï¿½^ï¿½ï¿½ï¿½Wï¿½Fï¿½ï¿½ï¿½gï¿½ï¿½0~1ï¿½Åiï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Ìï¿½ n*2-1ï¿½Åï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Kï¿½vï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#endif
#ifdef F_TARGET_XBOX360
#define MODEL_TANGENT_IS_UNSIGNED_NORMALIZE	// ï¿½^ï¿½ï¿½ï¿½Wï¿½Fï¿½ï¿½ï¿½gï¿½ï¿½0~1ï¿½Åiï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Ìï¿½ n*2-1ï¿½Åï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Kï¿½vï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#define CLONE_TANGENT_IS_UNSIGNED_NORMALIZE	// ï¿½^ï¿½ï¿½ï¿½Wï¿½Fï¿½ï¿½ï¿½gï¿½ï¿½0~1ï¿½Åiï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Ìï¿½ n*2-1ï¿½Åï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Kï¿½vï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
#endif
#endif

#ifdef MODEL_TANGENT_IS_UNSIGNED_NORMALIZE
#ifdef F_TARGET_PS3
void CORRECT_TANGNET_VALUE( inout float4 tan ) { tan.xyzw = tan.xyzw * 2.0 - 1.0 ;}
#else
void CORRECT_TANGNET_VALUE( inout float4 tan ) { tan.xyzw = tan.wzyx * 2.0 - 1.0 ;}// xbox360ï¿½Åï¿½xyzwï¿½Ìï¿½ï¿½Ñï¿½ï¿½tï¿½ÉÈï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ÌÅï¿½ï¿½Ìâ³ï¿½ï¿½
#endif
#else
#define CORRECT_TANGNET_VALUE(n) {}
#endif
#ifdef CLONE_TANGENT_IS_UNSIGNED_NORMALIZE
#ifdef F_TARGET_PS3
void CORRECT_CLONE_TANGNET_VALUE( inout float4 tan ) { tan.xyzw = tan.xyzw * 2.0 - 1.0 ;}
#else
void CORRECT_CLONE_TANGNET_VALUE( inout float4 tan ) { tan.xyzw = tan.wzyx * 2.0 - 1.0 ;}// xbox360ï¿½Åï¿½xyzwï¿½Ìï¿½ï¿½Ñï¿½ï¿½tï¿½ÉÈï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ÌÅï¿½ï¿½Ìâ³ï¿½ï¿½
#endif
#else
#define CORRECT_CLONE_TANGNET_VALUE(n) {}
#endif
// -----------------------------------------------------------------------


#ifdef F_TARGET_PS3
#define DG_ENABLE_HALFPIXELOFFSET
#endif
#ifdef DG_SHADER_GEN_DX11
#define DG_ENABLE_HALFPIXELOFFSET
#endif

#ifdef DG_ENABLE_HALFPIXELOFFSET
#define PIXELCENTEROFFSET (-0.5)
#else
#define PIXELCENTEROFFSET (0)
#endif

// VPos<->WPos ï¿½Ïï¿½
#ifdef F_TARGET_PS3 // ps3, dx11

#define ToVPos(wpos) (float2(wpos.x, g_psSystem.m_renderBuffer.y - wpos.y) + PIXELCENTEROFFSET)
#define ToVPos4(wpos) float4(ToVPos(wpos), 0, 0 )
#define ToWPos(wpos) (float2(wpos.x, g_psSystem.m_renderBuffer.y - wpos.y))
#define ToWPos4(wpos) float4(ToWPos(wpos), 0, 0)

#else // dx9, x360

#define ToVPos(vpos) (vpos + PIXELCENTEROFFSET)
#define ToVPos4 ToVPos
#define ToWPos(vpos) (vpos + 0.5f + PIXELCENTEROFFSET)
#define ToWPos4(vpos) ToWPos(vpos)

#endif


// ================================================================


#ifdef DG_SHADER_GEN_DX11

SamplerState g_samplerPoint_Wrap		: SAMPLERUNIT8;
SamplerState g_samplerPoint_Clamp	: SAMPLERUNIT9;
SamplerState g_samplerLinear_Wrap	: SAMPLERUNIT10;
SamplerState g_samplerLinear_Clamp	: SAMPLERUNIT11;
SamplerState g_samplerAnisotropic_Wrap : SAMPLERUNIT12;
SamplerState g_samplerAnisotropic_Clamp : SAMPLERUNIT13;
SamplerComparisonState g_samplerComparisonLess_Point_Clmap : SAMPLERUNIT14;
SamplerComparisonState g_samplerComparisonLess_Linear_Clmap : SAMPLERUNIT15;

#define SamplerPoint		g_samplerPoint_Wrap
#define SamplerPointClamp 	g_samplerPoint_Clamp
#define SamplerLinear	 	g_samplerLinear_Wrap
#define SamplerLinearClamp	g_samplerLinear_Clamp
#define SamplerAnisotropic	g_samplerAnisotropic_Wrap
#define SamplerAnisotropicClamp	g_samplerAnisotropic_Clamp
#define SamplerComparisonLess	g_samplerComparisonLess_Point_Clmap
#define SamplerComparisonLessLinear	g_samplerComparisonLess_Linear_Clmap

float2 CalcProjectCoords(float4 uv){
	return (uv/uv.w).xy;
}

#define TFetch(_texture, _sampler, _uv) 		_texture.Sample(_sampler, _uv)
#define TFetchOffset(_texture, _sampler, _uv, _offset) 		_texture.Sample(_sampler, _uv, _offset)

#define TFetch1D 								TFetch
#define TFetch1DOffset							TFetchOffset
#define TFetch2D 								TFetch
#define TFetch2DOffset							TFetchOffset
#define TFetch2DGrad							TFetchGrad
#define TFetch2DProj(_texture, _sampler, _uv) 	TFetch(_texture, _sampler, CalcProjectCoords(_uv))
//#define TFetch2DProj TFetch2DProjCmp
#define TFetch3D 								TFetch
#define TFetchCube 								TFetch
#define TFetchCubeBias(_texture, _sampler, _uv) _texture.SampleBias(_sampler, (_uv).xyz, (_uv).w)

#ifdef F_TARGET_PS4
#define TFetchGrad(_texture, _sampler, _uv, _dx, _dy) _texture.SampleGradient(_sampler, _uv, _dx, _dy)
#define TFetch2DLod(_texture, _sampler, _uv) 	_texture.SampleLOD(_sampler, (_uv).xy, (_uv).w)
#define TFetchCubeLod(_texture, _sampler, _uv)	_texture.SampleLOD(_sampler, (_uv).xyz, (_uv).w)
#else
#define TFetchGrad(_texture, _sampler, _uv, _dx, _dy) _texture.SampleGrad(_sampler, _uv, _dx, _dy)
#define TFetch2DLod(_texture, _sampler, _uv) 	_texture.SampleLevel(_sampler, (_uv).xy, (_uv).w)
#define TFetchCubeLod(_texture, _sampler, _uv)	_texture.SampleLevel(_sampler, (_uv).xyz, (_uv).w)
#endif // F_TARGET_PS4

float TFetch2DProjCmp(Texture2D _texture, SamplerComparisonState _sampler, float4 _uv){
	float3 prjectionUV = (_uv.xyz/_uv.w );
	return _texture.SampleCmp(_sampler, prjectionUV.xy, prjectionUV.z);
}

#define TFetchH(_texture, _sampler, _uv) ((half4)TFetch(_texture, _sampler, _uv))
#define TFetch1DH(_texture, _sampler, _uv) ((half4)TFetch1D(_texture, _sampler, _uv))
#define TFetch2DH(_texture, _sampler, _uv) ((half4)TFetch2D(_texture, _sampler, _uv))
#define TFetch2DProjH(_texture, _sampler, _uv) ((half4)TFetch2DProj(_texture, _sampler, _uv))
#define TFetch2DLodH(_texture, _sampler, _uv) ((half4)TFetch2DLod(_texture, _sampler, _uv))
#define TFetch3DH(_texture, _sampler, _uv) ((half4)TFetch3D(_texture, _sampler, _uv))
#define TFetch2DProjCmpH(_texture, _sampler, _uv) ((half4)TFetch2DProjCmp(_texture, _sampler, _uv))
#define TFetch2DGradH(_texture, _sampler, _uv, _dx, _dy) ((half4)TFetch2DGrad(_texture, _sampler, _uv, _dx, _dy))

#else

#define Texture1D sampler
#define Texture2D sampler
#define Texture2DArray sampler
#define Texture3D sampler
#define TextureCube sampler
#define TextureCubeArray sampler
#define SamplerState sampler

#define TFetch1D(_texture, _sampler, _uv)		tex1D(_texture, _uv)
#define TFetch2D(_texture, _sampler, _uv)		tex2D(_texture, _uv)
#define TFetch2DGrad(_texture, _sampler, _uv, _dx, _dy) tex2D(_texture, _uv, _dx, _dy)
#define TFetch2DProj(_texture, _sampler, _uv)	tex2Dproj(_texture, _uv)
#define TFetch2DLod(_texture, _sampler, _uv)	tex2Dlod(_texture, _uv)
#define TFetch3D(_texture, _sampler, _uv)		tex3D(_texture, _uv)
#define TFetchCube(_texture, _sampler, _uv)	texCUBE(_texture, _uv)
#define TFetchCubeBias(_texture, _sampler, _uv)	texCUBEbias(_texture, _uv)
#define TFetchCubeLod(_texture, _sampler, _uv)	texCUBElod(_texture, _uv)
#define TFetch2DProjCmp TFetch2DProj

#define TFetch1DH(_texture, _sampler, _uv) 		h4tex1D(_texture, _uv)
#define TFetch2DH(_texture, _sampler, _uv) 		h4tex2D(_texture, _uv)
#define TFetch2DGradH(_texture, _sampler, _uv, _dx, _dy) h4tex2D(_texture, _uv, _dx, _dy)
#define TFetch2DProjH(_texture, _sampler, _uv)	h4tex2Dproj(_texture, _uv)
#define TFetch2DLodH(_texture, _sampler, _uv)	h4tex2Dlod(_texture, _uv)
#define TFetch3DH(_texture, _sampler, _uv)		h4tex3D(_texture, _uv)
#define TFetch2DProjCmpH TFetch2DProjH

#define SamplerPoint		0
#define SamplerPointClamp 	0
#define SamplerLinear	 	0
#define SamplerLinearClamp	0
#define SamplerAnisotropic	0
#define SamplerAnisotropicClamp	0
#define SamplerComparisonLess	0
#define SamplerComparisonLessLinear	0
#endif

// ----------------------------------------------------------------
/**	@brief Encode 2 float value to 4 8-bit integer values
	@param	v	the original value
	@return		the encoded value
 */
half4 packFP16(float2 v)
{
	//const float2 msk2 = float2(0,1.0/256.0);
    float4 _packed;
    
    //packed.yw = v.xy;
    //packed.xz = frac(256.0*v.xy);
	//packed.xyzw = packed.xyzw - packed.xxzz * msk2.xyxy;
	// GPUï¿½ÉDï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	_packed.xz = frac(256.0*v.xy);
	_packed.yw = _packed.xz * ( -1.0 / 256.0 ) + v.xy ;
    
    return half4(_packed);
}

// ----------------------------------------------------------------
/**	@brief Encode a float value to 4 8-bit integer values
	@param	v	the original value
	@return		the encoded value
 */
half4 packFP32(float v)
{
    // MSB first, so w can be discarded when precission is needed
	float4 p = v * float4(1.0, 256.0, (256.0*256.0), (256.0*256.0*256.0));
	return half4(floor(frac(p) * 256.0) * (1.0 / 255.0));
}

// ----------------------------------------------------------------
// Gï¿½oï¿½bï¿½tï¿½@ï¿½Ìfï¿½Rï¿½[ï¿½h
/// Decodes 2 float values from 4 8-bit integer values
/// @param[in] packed The encoded values, where packed.xy corresponds to the first value, and packed.zw to the second
/// @return the decoded value
float2 unpackFP16(float4 _packed)
{
	const float2 bitSh = float2(1.0/256.0, 1.0);
	float2 _unpacked;
	_unpacked.x = dot(_packed.xy, bitSh);
	_unpacked.y = dot(_packed.zw, bitSh);    
    return _unpacked;
}

/// Decodes a float value from 4 8-bit integer values
/// @param[in] packed The encoded value
/// @return the decoded value
float unpackFP32(float4 _packed)
{
	return dot(_packed, float4(
        (255.0/256.0),
        (255.0/(256.0*256.0)),
        (255.0/(256.0*256.0*256.0)),
        (255.0/(256.0*256.0*256.0*256.0))
        ) );
}

// -------------------------------------------------------------------------
/** @brief Writes specular and velocity in proper order for GBuffer
	old version
	cannot use this function
  */
inline half4 WriteSpecularAndVelocity( half2 inSpecular, half2 inVelocity )
{
    half4 outColor ;
    outColor.xy = inSpecular;
    outColor.zw = inVelocity;
    return outColor ;
}

// -------------------------------------------------------------------------
/** @brief Reads specular in proper order from GBuffer
  */
inline half2 ReadSpecular( half4 inColor )
{
    return inColor.xy ;
}

// -------------------------------------------------------------------------
/** @brief Reads specular in proper order from GBuffer
  */
inline half2 ReadVelocity( half4 inColor )
{
    return inColor.zw ;
}

// -----------------------------------------------------------------------
/** @brief Matting function for "Depth-of-Field Rendering by Pyramidal Image Processing"
 */
inline half PyramidalDoFMatting( float z, float4 zThresholds )
{
    float z_2 = zThresholds.x ;
    float z_1 = zThresholds.y ;
    float z0  = zThresholds.z ;
    float z1  = zThresholds.w ;
    
    half matting = 1;
    if ( z < z_1 ) {
        matting = (z_1 <= z_2) ? 0 : // step
            half( saturate( ( z - z_2 ) / ( z_1 - z_2 ) ) ); // ramp
    } else if ( z > z0 ) {
        matting = half( saturate( ( z1 - z ) / ( z1 - z0 ) ) );
    }
    
    return matting ;
}

// -----------------------------------------------------------------------
/** @brief Calcurate Global Volumetric Fog Density
	@param[in] cameraToWorldPos 					: vector from camera to point of the object
	@param[in] globalDensity						: global fog density
	@param[in] heightFallOff						: height fall off
	@param[in] volumetricFogHeightDensityAtViewer	:
	@return fog density
 */
float CalcGlobalVolumetricFogDensity(float3 cameraToWorldPos, float globalDensity, float heightFallOff, float volumetricFogHeightDensityAtViewer)
{
	// ï¿½Jï¿½ï¿½ï¿½ï¿½ï¿½ÆIï¿½uï¿½Wï¿½Fï¿½Nï¿½gï¿½ÔÌï¿½ï¿½ï¿½ï¿½ï¿½ï¿½lï¿½ï¿½
	float fogInt = length(cameraToWorldPos) * volumetricFogHeightDensityAtViewer;
	
	// ï¿½Jï¿½ï¿½ï¿½ï¿½ï¿½ÆIï¿½uï¿½Wï¿½Fï¿½Nï¿½gï¿½ÔÉï¿½ï¿½xï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½êï¿½Ìeï¿½ï¿½ï¿½ï¿½ï¿½lï¿½ï¿½
	//const float SLOPE_THREASHOLD = 0.01;
	float t = max( heightFallOff * cameraToWorldPos.y, 0.00001 );
//	if ( abs(cameraToWorldPos.y) > SLOPE_THREASHOLD)
//	{
//		float t = heightFallOff * cameraToWorldPos.y;
		fogInt *= (1.0f - exp(-t)) / t;
//	}
	
	return exp(-globalDensity * fogInt);
}
		
// -----------------------------------------------------------------------
/** @brief Calcurate fresnel factor for specular
	@param[in] halfDir	: LightDir + ViewDir
	@param[in] lightDir	: LightDir
	@param[in] f0	: f0
	@return fresnel factor
 */
#ifdef USEDEFINE_GetFresnel
#define GetFresnelSpecularFactor(halfDir,lightDir,f0) \
	(f0 + ( 1.0H - f0 ) * ( half( pow ( abs(1.0H - half( saturate( dot ( halfDir, lightDir ) ) )), 5.0H ) ) ))
#else
half GetFresnelSpecularFactor ( half3 halfDir, half3 lightDir, half f0 )
{
#ifdef USE_SPHERICAL_GAUSSIAN_FRESNLE
	//powï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÌÅï¿½ï¿½ï¿½ï¿½ÉÈï¿½
	half cosValue = half( saturate( dot ( halfDir, lightDir ) ) );
	return f0 + ( 1.0H - f0 ) * (half)exp2 ( ( -5.55473h * cosValue - 6.98316h ) * cosValue );
#else
	return f0 + ( 1.0H - f0 ) * ( half( pow ( abs(1.0H - half( saturate( dot ( halfDir, lightDir ) ) )), 5.0H ) ) );
#endif
}
#endif

// -----------------------------------------------------------------------
/** @brief Adjust Point Light Size from distance
	@param[in] size : sin(RAD) LightSize
	@param[in] dist : distance
	@return sin(RAD) LightSize
 */
half AdjustLightSizeFromDistance( half size, float dist )
{
	//ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Åï¿½ï¿½Hï¿½ï¿½ï¿½æ¤
	//ï¿½Æè ï¿½ï¿½ï¿½ï¿½1mï¿½Ìï¿½ï¿½ÉAï¿½wï¿½èï¿½ï¿½ï¿½pï¿½Æï¿½ï¿½ÄAï¿½ï¿½ï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½Ågï¿½ï¿½ï¿½kï¿½ï¿½ï¿½ï¿½ï¿½ÄÝï¿½

	//ï¿½ï¿½ï¿½mï¿½ÉÍpï¿½xï¿½Íï¿½ï¿½ï¿½ï¿½Éï¿½ï¿½áµï¿½Èï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½0.9ï¿½{ï¿½Éï¿½ï¿½ï¿½ï¿½ßï¿½ï¿½Æï¿½ï¿½ï¿½
	//atan2(0.5,1) = 0.463648
	//atan2(0.5,2) = 0.244979 = 0.463648 / (2*0.9)
	//atan2(0.5,10) = 0.049958 = 0.463648 / (10*0.9)
	
	return (half)saturate ( size * 1.0H /  dist * 0.9 ) ;
}


// reflection
// -----------------------------------------------------------------------
/** @brief GetReflection with Roughness
	@param[out] refVec : reflection vector(view space)
	@param[in] refTex : cubemap texture
	@param[in] viewVec : view space view vector
	@param[in] normalVec : view space normal vector
	@param[in] raghnessRate : roughness-blend rate
	@param[in] mat : view to world
	@return color
 */
half3 GetReflectionWithRoughness( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2;
	ref_vec2.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );
	ref_vec2 = half4 ( ref_vec2.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	//w=bias

#ifdef USER_TEXCUBELOD
	//return half3( GammaDecode ( TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz ) );
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;
#else
	//return half3( GammaDecode ( TFetchCubeBias( refTex, SamplerLinear, ref_vec2 ).xyz ) );
	return (half3)TFetchCubeBias( refTex, SamplerLinear, ref_vec2 ).xyz;
#endif
}

// -----------------------------------------------------------------------
/** @brief GetReflection
	@param[out] refVec : reflection vector
	@param[in] refTex : cubemap texture
	@param[in] viewVec : view space view vector
	@param[in] normalVec : view space normal vector
	@param[in] mat : view to world
	@return color
 */
half3 GetReflection( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	refVec.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );

//	return half3( GammaDecode ( TFetchCube( refTex, SamplerLinear, refVec ).xyz ) );
	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}

// -----------------------------------------------------------------------
/** @brief GetReflection with Roughness : WorldSpace
	@param[out] refVec : reflection vector(world space)
	@param[in] refTex : cubemap texture
	@param[in] viewVec : world space view vector
	@param[in] normalVec : view space normal vector
	@param[in] raghnessRate : roughness-blend rate
	@return color
 */
half3 GetReflectionWithRoughness_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2 = half4 ( refVec.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	//w=bias

#ifdef USER_TEXCUBELOD
	//return half3( GammaDecode ( TFetchCubeLod( refTex, ref_vec2 ).xyz ) );
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;
#else
	//return half3( GammaDecode ( TFetchCubeBias ( refTex, ref_vec2 ).xyz ) );
	return (half3)TFetchCubeBias( refTex, SamplerLinear, ref_vec2 ).xyz;
#endif
}

// -----------------------------------------------------------------------
/** @brief GetReflection : WorldSpace
	@param[out] refVec : reflection vector
	@param[in] refTex : cubemap texture
	@param[in] viewVec : world space view vector
	@param[in] normalVec : view space normal vector
	@return color
 */
half3 GetReflection_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;

	//return half3( GammaDecode ( TFetchCube( refTex, refVec ).xyz ) );
	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}

// -----------------------------------------------------------------------
/**
	Selectï¿½Wï¿½J
	if ( a < 0 ){
		return b;
	} else {
		return c;
	}
*/
half4 select ( half4 a, half4 b, half4 c )
{
	half4 sel = (half4)step ( half4 ( 0,0,0,0 ), a ) ;
	return sel * c + (half4 ( 1,1,1,1 ) - sel) * b;
}
half3 select ( half3 a, half3 b, half3 c )
{
	half3 sel = (half3)step ( half3 ( 0,0,0 ), a ) ;
	return sel * c + (half3 ( 1,1,1 ) - sel) * b;
}
half2 select ( half2 a, half2 b, half2 c )
{
	half2 sel = (half2)step ( half2 ( 0,0 ), a ) ;
	return sel * c + (half2 ( 1,1 ) - sel) * b;
}
half select ( half a, half b, half c )
{
	half sel = (half)step ( 0, a ) ;
	return sel * c + ( 1.0H - sel) * b;
}

// -----------------------------------------------------------------------
/** @brief Blend color like Photoshop Overlay layer
	@param[in] baseColor : base
	@param[in] layerColor : layer
	@param[in] blendRate : rate
	@param[in] raghnessRate : roughness-blend rate
	@return color
 */
half3 GetBlendColor_Overlay ( half3 baseColor, half3 layerColor, half blendRate )
{
	half3 color0 = baseColor.xyz * layerColor.xyz * 2;	//ï¿½ï¿½ï¿½Z
	half3 color1 = 1.0H - ( 1.0H - baseColor.xyz) * ( 1.0H - layerColor.xyz ) * 2;	//ï¿½Xï¿½Nï¿½ï¿½ï¿½[ï¿½ï¿½
	half3 outColor = select ( baseColor - 0.5H, color0, color1 );
	
	return (half3) lerp ( baseColor.xyz, outColor, blendRate );
}

// -----------------------------------------------------------------------
/** @brief Create Checker pattern
	@param[in] uv : uv
	@param[in] repert : repeat count
	@return color
*/
half GetCheckerPattern ( half2 uv, half repeat )
{
	half2 checker = (half2)step ( 0.5h, (half2)frac ( uv.xy * repeat ) ) ;
	return ( 1.0h- abs( checker.x - checker.y ) );
}

#define DIRTY_BLEND_AFTER_REFLECTION

half3 BlendDirtyColorSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask )
{
	half3 outColor;
	
	//ï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½Dï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	//ï¿½bï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½ï¿½ï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	half3 blend = mask.xyz * dirtyColor.xyz ;
	
	//ï¿½ï¿½ï¿½ðÎÏï¿½ï¿½Éï¿½ï¿½ï¿½
	half waterScaleBase			 = min ( 0.93H, max (0.73H, (roughness * 255.0H - 205.0H) / 25.0H * (-0.20H) + 0.93H ));
	half waterScaleRoughness	 = min ( 0.66H, (half)saturate ( (roughness * 255.0H - 170.0H) / 60.0H * 0.66H ) );
	
	//ï¿½{ï¿½ï¿½ï¿½ï¿½SRGBï¿½ï¿½ï¿½ï¿½Linearï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Aï¿½dï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½Éï¿½ï¿½ï¿½ï¿½ï¿½ï¿½xï¿½ÈÌï¿½SRGBï¿½ÌÜÜuï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ï¿½ï¿½ÆÉï¿½ï¿½ï¿½
//	outColor = (half3)lerp ( inColor, half3 (0.439215686H, 0.364705882H, 0.274509804H), blend.zzz );			//ï¿½D  (112,93,70)
	outColor = (half3)lerp ( inColor, inColor * waterScaleBase.xxx, blend.zzz );								//ï¿½ï¿½  waterScale
#ifndef DIRTY_WATERONLY
	outColor = (half3)lerp ( outColor, half3 (0.2H, 0.196078431H, 0.192156863H), blend.yyy );					//ï¿½ï¿½ï¿½ï¿½(51,50,49)
//	outColor = (half3)lerp ( outColor, half3 (0.333333333H, 0.066666667H, 0.066666667H), blend.xxx );			//ï¿½ï¿½  (85,17,17)
	outColor = (half3)lerp ( outColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						//ï¿½ï¿½  (85,17,17) >> ï¿½ÏXï¿½Aï¿½i66,12,11ï¿½j
#endif
	
//	outRoughness = (half)lerp ( roughness,	0.8H,	blend.z );			//ï¿½D0.8
	outRoughness = (half)lerp ( roughness,	roughness * waterScaleRoughness.x,	blend.z );			//ï¿½ï¿½ waterScale
#ifndef DIRTY_WATERONLY
	outRoughness = (half)lerp ( outRoughness,	0.98H,	blend.y );		//ï¿½ï¿½ï¿½ï¿½0.98
	outRoughness = (half)lerp ( outRoughness,	0.2H,	blend.x );		//ï¿½ï¿½ 0.2
#endif
	
	return outColor;

}
half3 BlendDirtyColorRoughnessMaskSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask, half3 roughnessMask )
{
	half3 outColor;
	
	//ï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½Dï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	//ï¿½bï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½ï¿½ï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	half3 blend = mask.xyz * dirtyColor.xyz ;
	half3 blendR = roughnessMask.xyz * dirtyColor.xyz ;
	
	//ï¿½ï¿½ï¿½ðÎÏï¿½ï¿½Éï¿½ï¿½ï¿½
	half waterScaleBase			 = min ( 0.93H, max (0.73H, (roughness * 255.0H - 205.0H) / 25.0H * (-0.20H) + 0.93H ));
	half waterScaleRoughness	 = min ( 0.66H, (half)saturate ( (roughness * 255.0H - 170.0H) / 60.0H * 0.66H ) );
	
	//ï¿½{ï¿½ï¿½ï¿½ï¿½SRGBï¿½ï¿½ï¿½ï¿½Linearï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Aï¿½dï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½Éï¿½ï¿½ï¿½ï¿½ï¿½ï¿½xï¿½ÈÌï¿½SRGBï¿½ÌÜÜuï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ï¿½ï¿½ÆÉï¿½ï¿½ï¿½
//	outColor = (half3)lerp ( inColor, half3 (0.439215686H, 0.364705882H, 0.274509804H), blend.zzz );			//ï¿½D  (112,93,70)
	outColor = (half3)lerp ( inColor, inColor * waterScaleBase.xxx, blend.zzz );								//ï¿½ï¿½  waterScale
	outColor = (half3)lerp ( outColor, half3 (0.2H, 0.196078431H, 0.192156863H), blend.yyy );					//ï¿½ï¿½ï¿½ï¿½(51,50,49)
//	outColor = (half3)lerp ( outColor, half3 (0.333333333H, 0.066666667H, 0.066666667H), blend.xxx );			//ï¿½ï¿½  (85,17,17)
	outColor = (half3)lerp ( outColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						//ï¿½ï¿½  (85,17,17) >> ï¿½ÏXï¿½Aï¿½i66,12,11ï¿½j
	
//	outRoughness = (half)lerp ( roughness,	0.8H,	blend.z );			//ï¿½D0.8
	outRoughness = (half)lerp ( roughness,	roughness * waterScaleRoughness.x,	blendR.z );			//ï¿½ï¿½ waterScale
	outRoughness = (half)lerp ( outRoughness,	0.98H,	blendR.y );		//ï¿½ï¿½ï¿½ï¿½0.98
	outRoughness = (half)lerp ( outRoughness,	0.2H,	blendR.x );		//ï¿½ï¿½ 0.2
	
	return outColor;

}

// -----------------------------------------------------------------------
/** @brief Blend Dirty Color
	@param[out] outRoughness : blended roughness
	@param[in] dirtyTexture : dirtyTexture
	@param[in] texcoord : texcoord for dirtyTexture
	@param[in] inColor : albedo color
	@param[in] roughness : original roughness
	@param[in] mask : blend mask
	@return color
*/
half3 BlendDirtyColor ( out half outRoughness, Texture2D dirtyTexture, float2 texcoord, half3 inColor, half roughness, half3 mask )
{
	half4 dirtyTex = TFetch2DH( dirtyTexture, SamplerLinear, texcoord );
	return BlendDirtyColorSub(outRoughness, dirtyTex, inColor, roughness, mask);
}
half3 BlendDirtyColorRoughnessMask ( out half outRoughness, Texture2D dirtyTexture, float2 texcoord, half3 inColor, half roughness, half3 mask, half3 roughnessMask )
{
	half4 dirtyTex = TFetch2DH( dirtyTexture, SamplerLinear, texcoord );
	return BlendDirtyColorRoughnessMaskSub(outRoughness, dirtyTex, inColor, roughness, mask, roughnessMask);
}

half3 BlendDirtyColorWithSampler ( out half outRoughness, Texture2D dirtyTexture, SamplerState dirtySampler, float2 texcoord, half3 inColor, half roughness, half3 mask )
{
	//ï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½Dï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	//ï¿½bï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½ï¿½ï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	half4 dirtyTex = TFetch2DH( dirtyTexture, dirtySampler, texcoord );
	return BlendDirtyColorSub(outRoughness, dirtyTex, inColor, roughness, mask);
}
half3 BlendDirtyColorWithSamplerRoughnessMask ( out half outRoughness, Texture2D dirtyTexture, SamplerState dirtySampler, float2 texcoord, half3 inColor, half roughness, half3 mask, half3 roughnessMask )
{
	//ï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½Dï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	//ï¿½bï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½ï¿½ï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	half4 dirtyTex = TFetch2DH( dirtyTexture, dirtySampler, texcoord );
	return BlendDirtyColorRoughnessMaskSub(outRoughness, dirtyTex, inColor, roughness, mask, roughnessMask);
}


half3 BlendDirtyColorRSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask )
{
	half3 outColor;
	
	//ï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½Dï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	//ï¿½bï¿½ï¿½ï¿½dï¿½lï¿½FB:ï¿½ï¿½ï¿½AG:ï¿½ï¿½ï¿½ï¿½ï¿½AR:ï¿½ï¿½
	half3 blend = mask.xyz * dirtyColor.xyz ;
	
	//ï¿½ï¿½ï¿½ðÎÏï¿½ï¿½Éï¿½ï¿½ï¿½
//	half waterScaleBase			 = min ( 0.93H, max (0.73H, (roughness * 255.0H - 205.0H) / 25.0H * (-0.20H) + 0.93H ));
//	half waterScaleRoughness	 = min ( 0.66H, (half)saturate ( (roughness * 255.0H - 170.0H) / 60.0H * 0.66H ) );
	
	//ï¿½{ï¿½ï¿½ï¿½ï¿½SRGBï¿½ï¿½ï¿½ï¿½Linearï¿½ï¿½ï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Aï¿½dï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½Éï¿½ï¿½ï¿½ï¿½ï¿½ï¿½xï¿½ÈÌï¿½SRGBï¿½ÌÜÜuï¿½ï¿½ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½Äï¿½ï¿½Üï¿½ï¿½ï¿½ï¿½ÆÉï¿½ï¿½ï¿½
//	outColor = (half3)lerp ( inColor, half3 (0.333333333H, 0.066666667H, 0.066666667H), blend.xxx );			//ï¿½ï¿½  (85,17,17)
	outColor = (half3)lerp ( inColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						//ï¿½ï¿½  (85,17,17) >> ï¿½ÏXï¿½Aï¿½i66,12,11ï¿½j
	outRoughness = (half)lerp ( roughness,	0.2H,	blend.x );		//ï¿½ï¿½ 0.2
	
	return outColor;

}

// -----------------------------------------------------------------------
/** @brief Blend Dirty Color R
	@param[out] outRoughness : blended roughness
	@param[in] dirtyTexture : dirtyTexture
	@param[in] texcoord : texcoord for dirtyTexture
	@param[in] inColor : albedo color
	@param[in] roughness : original roughness
	@param[in] mask : blend mask
	@return color
*/
half3 BlendDirtyColorR ( out half outRoughness, Texture2D dirtyTexture, float2 texcoord, half3 inColor, half roughness, half3 mask )
{
	half4 dirtyTex = (half4)TFetch2D ( dirtyTexture, SamplerLinear, texcoord );
	return BlendDirtyColorRSub(outRoughness, dirtyTex, inColor, roughness, mask);
}

half3 BlendDirtyColorRWithSampler ( out half outRoughness, Texture2D dirtyTexture, SamplerState dirtySampler, float2 texcoord, half3 inColor, half roughness, half3 mask )
{
	half4 dirtyTex = (half4)TFetch2D ( dirtyTexture, dirtySampler, texcoord );
	return BlendDirtyColorRSub(outRoughness, dirtyTex, inColor, roughness, mask);
}

#endif /* _SHADER_H_ */

