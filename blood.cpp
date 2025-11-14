#line 8 "..\Fx\Shader\Prim_Decal_Blood.shdr"



#line 8 "..\Gr\Dg\shader\Primitive.shdr"


#define DISABLE_BONE_REGISTERS

#line 1 "..\Gr\Dg\shader\Common.shdr"


#line 2 "..\Gr\Dg\shader\shader.h"













#line 4 "..\Gr\Dg\shader\../DgShaderDefine.h"



#define _DG_SHADER_DEF_H_


#line 60 "..\Gr\Dg\shader\../DgShaderDefine.h"




#line 230 "..\Gr\Dg\shader\../DgShaderDefine.h"





#define REGISTER_C(_var)	register(c##_var)
#define REGISTER_B(_var)	register(b##_var)
#define REGISTER_I(_var)	register(i##_var)
#define REGISTER_T(_var)	register(t##_var)
#define REGISTER_S(_var)	register(s##_var)


typedef float4x4			Matrix4x4 ;
typedef float4x4			TMatrix4x4 ;
typedef float4x3			TMatrix4x3 ;


typedef float3			TANGENT2VIEW[3] ;
typedef half3			HTANGENT2VIEW[3] ;
typedef float3			TANGENT2WORLD[3] ;
typedef half3			HTANGENT2WORLD[3] ;



#line 320 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define TEXUNIT0		register(t0)
#define TEXUNIT1		register(t1)
#define TEXUNIT2		register(t2)
#define TEXUNIT3		register(t3)
#define TEXUNIT4		register(t4)
#define TEXUNIT5		register(t5)
#define TEXUNIT6		register(t6)
#define TEXUNIT7		register(t7)
#define TEXUNIT8		register(t8)
#define TEXUNIT9		register(t9)
#define TEXUNIT10		register(t10)
#define TEXUNIT11		register(t11)
#define TEXUNIT12		register(t12)
#define TEXUNIT13		register(t13)
#define TEXUNIT14		register(t14)
#define TEXUNIT15		register(t15)
#define	SAMPLERUNIT0	register(s0)
#define	SAMPLERUNIT1	register(s1)
#define	SAMPLERUNIT2	register(s2)
#define	SAMPLERUNIT3	register(s3)
#define	SAMPLERUNIT4	register(s4)
#define	SAMPLERUNIT5	register(s5)
#define	SAMPLERUNIT6	register(s6)
#define	SAMPLERUNIT7	register(s7)
#define	SAMPLERUNIT8	register(s8)
#define	SAMPLERUNIT9	register(s9)
#define	SAMPLERUNIT10	register(s10)
#define	SAMPLERUNIT11	register(s11)
#define	SAMPLERUNIT12	register(s12)
#define	SAMPLERUNIT13	register(s13)
#define	SAMPLERUNIT14	register(s14)
#define	SAMPLERUNIT15	register(s15)

#define SAMPLERUNIT_SYSTEM SAMPLERUNIT8


#line 372 "..\Gr\Dg\shader\../DgShaderDefine.h"
	

#define OUT_COLOR		SV_Target0
#define OUT_COLOR0		SV_Target0
#define OUT_COLOR1		SV_Target1
#define OUT_COLOR2		SV_Target2
#define OUT_COLOR3		SV_Target3
#define OUT_DEPTH		SV_Depth
#define OUT_POSITION	SV_Position
#define VPOS			SV_Position
#define VFACE			SV_IsFrontFace
#define OUT_CLIPDISTANCE SV_ClipDistance
#define VINDEXID		SV_VertexID
#define VINSTANCEID		SV_InstanceID
#define VPRIMITIVEID	SV_PrimitiveID
	
typedef bool			vface;

bool isFrontFace(vface face)
{
	return face;
}
float getFaceSign(vface face)
{
	return face?1:-1;
}
	
	
	

inline float4 ApplyMatrix( Matrix4x4 mat, float4 vec )
{
	return mul( mat, vec );
}
inline float4 ApplyMatrixT( TMatrix4x4 mat, float4 vec )
{
	return mul( vec, mat );
}
inline float3 ApplyMatrixT( TMatrix4x4 mat, float3 vec )
{
	return mul( float4(vec, 0), mat ).xyz;
}
inline float3 ApplyMatrixT( TMatrix4x3 mat, float4 vec )
{
	return mul( vec, mat );
}
inline float3 ApplyMatrixT( TMatrix4x3 mat, float3 vec )
{
	return mul( float4(vec, 0), mat );
}
inline float3 ApplyMatrixT( TANGENT2WORLD mat, float3 vec )
{
	return mul( vec, float3x3(mat[0], mat[1], mat[2]) );
}
inline void SetTranslate( inout Matrix4x4 mat, float4 translate )
{
	mat[0].w = translate.x ;
	mat[1].w = translate.y ;
	mat[2].w = translate.z ;
	mat[3].w = translate.w ;
}
inline void SetTranslateT( inout TMatrix4x4 mat, float4 translate )
{
	mat[3].xyzw = translate.xyzw ;
}
inline void SetTranslateT( inout TMatrix4x3 mat, float3 translate )
{
	mat[3].xyz = translate.xyz ;
}
inline float4 GetTranslate( Matrix4x4 mat )
{
	return float4( mat[0].w, mat[1].w, mat[2].w, mat[3].w );
}
inline float4 GetTranslateT( TMatrix4x4 mat )
{
	return mat[3].xyzw ;
}
inline float3 GetTranslateT( TMatrix4x3 mat )
{
	return mat[3].xyz ;
}
inline TMatrix4x4 GetTranspose( TMatrix4x4 mat )
{
	return transpose ( mat );
}
inline float4 GetRow( TMatrix4x4 mat, half _row )
{
	return float4( mat[0][(int)_row], mat[1][(int)_row], mat[2][(int)_row], mat[3][(int)_row]);
}
inline float4 GetRowT( TMatrix4x4 mat, half _row )
{
	return mat[(int)_row].xyzw;
}
inline float3 GetRow( TMatrix4x3 mat, half _row )
{
	return float3( mat[0][(int)_row], mat[1][(int)_row], mat[2][(int)_row] );
}
inline float3 GetRowT( TMatrix4x3 mat, half _row )
{
	return mat[(int)_row].xyz;
}
inline float GetElement( TMatrix4x4 mat, half _row, half _column )
{
	return mat[(int)_row][(int)_column];
}

inline float3 GetViewspaceWorldXDir ( TMatrix4x4 invViewMat ){
	return float3 ( invViewMat[0][0], invViewMat[0][1], invViewMat[0][2] );
}
inline float3 GetViewspaceWorldYDir ( TMatrix4x4 invViewMat ){
	return float3 ( invViewMat[1][0], invViewMat[1][1], invViewMat[1][2] );
}
inline float3 GetViewspaceWorldZDir ( TMatrix4x4 invViewMat ){
	return float3 ( invViewMat[2][0], invViewMat[2][1], invViewMat[2][2] );
}


#line 492 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 494 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 498 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 6 "..\Gr\Dg\shader\../DgShaderDefineForDx11Gen.h"


#define _DG_SHADER_DEF_FOR_DIRECTX11_GEN_H_




#define SHADER_CONSTANTBUFFER_SYSTEM		0
#define SHADER_CONSTANTBUFFER_RENDERBUFFER	1
#define SHADER_CONSTANTBUFFER_SCENE			2
#define SHADER_CONSTANTBUFFER_LIGHTS		3
#define SHADER_CONSTANTBUFFER_MATERIAL		4
#define SHADER_CONSTANTBUFFER_OBJECT		5
#define SHADER_CONSTANTBUFFER_BONES			6
#define SHADER_CONSTANTBUFFER_WORK			7


#define SHADER_CONSTANTBUFFER_LIGHT			SHADER_CONSTANTBUFFER_LIGHTS



struct SSystem
{
	float4		m_param;					
	float4		m_renderInfo;				
	float4		m_renderBuffer ;			
	float4		m_dominantLightDir;			
};
typedef SSystem VSSystem;
typedef SSystem PSSystem;

#define SHADER_CONST_SYSTEM_PARAM				0
#define SHADER_CONST_SYSTEM_RENDERINFO			1
#define SHADER_CONST_SYSTEM_RENDERBUFFER		2
#define SHADER_CONST_SYSTEM_DOMINANT_LIGHT_DIR	3
#define SHADER_CONSTANTBUFFER_SYSTEM_SIZE		4




struct SScene
{
	TMatrix4x4		m_projectionView;		
	TMatrix4x4		m_projection;			
	TMatrix4x4		m_view;					
	TMatrix4x4		m_shadowProjection;		
	TMatrix4x4		m_shadowProjection2;	
	float4			m_eyepos;				
	float4			m_projectionParam;		
	float4			m_viewportSize;			
	float4			m_exposure;				
	float4			m_fogParam[3];			
	float4			m_fogColor;				
	float4			m_cameraCenterOffset;	
	float4			m_shadowMapResolutions;	
};
typedef SScene VSScene;
typedef SScene PSScene;

#define SHADER_CONST_PROJECTIONVIEW				0
#define SHADER_CONST_PROJECTION					4
#define SHADER_CONST_VIEW						8
#define SHADER_CONST_SHADOWPROJECTION			12
#define SHADER_CONST_SHADOWPROJECTION2			16
#define SHADER_CONST_EYEPOS						20
#define SHADER_CONST_PROJECTIONPARAM			21
#define SHADER_CONST_VIEWPORTSIZE				22
#define SHADER_CONST_EXPOSURE					23
#define SHADER_CONST_FOGPARAM0					24
#define SHADER_CONST_FOGPARAM1					25
#define SHADER_CONST_FOGPARAM2					26
#define SHADER_CONST_FOGCOLOR					27
#define SHADER_CONST_CAMERACENTEROFFSET			28
#define SHADER_CONST_SHADOWMAP_RESOLUTIONS		29
#define SHADER_CONSTANTBUFFER_SCENE_SIZE		30




struct SRenderBuffer
{
	float4		m_size;						
};
typedef SRenderBuffer PSRenderBuffer;

#define SHADER_CONST_RENDERBUFFER_SIZE			0
#define SHADER_CONSTANTBUFFER_RENDERBUFFER_SIZE	1




#define SHADER_CONST_LIGHTPARAM0				0
#define SHADER_CONST_LIGHTPARAM1				1
#define SHADER_CONST_LIGHTPARAM2				2
#define	SHADER_CONST_LIGHTPARAM3				3
#define	SHADER_CONST_LIGHTPARAM4				4
#define	SHADER_CONST_LIGHTPARAM5				5
#define	SHADER_CONST_LIGHTPARAM6				6
#define	SHADER_CONST_LIGHTPARAM7				7
#define	SHADER_CONST_LIGHTPARAM8				8
#define SHADER_CONST_LIGHTPARAM9		 		9
#define SHADER_CONST_LIGHTPARAM10				10
#define SHADER_CONSTANTBUFFER_LIGHTS_SIZE		11

struct SLights
{
	float4		m_lightParams[SHADER_CONSTANTBUFFER_LIGHTS_SIZE];
};
typedef SLights VSLight;
typedef SLights PSLight;





#define SHADER_CONST_MATERIAL0					0
#define SHADER_CONST_MATERIAL1					1
#define SHADER_CONST_MATERIAL2					2
#define SHADER_CONST_MATERIAL3					3
#define SHADER_CONST_MATERIAL4					4
#define SHADER_CONST_MATERIAL5					5
#define SHADER_CONST_MATERIAL6					6
#define SHADER_CONST_MATERIAL7					7
#define SHADER_CONSTAMTBUFFER_MATERIAL_SIZE		8

struct SMaterial
{
	float4		m_materials[SHADER_CONSTAMTBUFFER_MATERIAL_SIZE] ;
};
typedef SMaterial VSMaterial;
typedef SMaterial PSMaterial;




struct SObjectBase
{
	TMatrix4x4		m_viewWorld ;			
	TMatrix4x4		m_world ;				
	float4			m_useWeightCount ;		
};



struct SObject
{
	TMatrix4x4		m_viewWorld ;			
	TMatrix4x4		m_world ;				
	float4			m_useWeightCount ;		
	float4			m_localParam[4] ;		
};
typedef SObject VSObject;
typedef SObject PSObject;

#define SHADER_CONST_VIEWWORLD					0
#define SHADER_CONST_WORLD						4
#define SHADER_CONST_USEWEIGHTCOUNT				8
#define SHADER_CONST_LOCALPARAM0				9
#define SHADER_CONST_LOCALPARAM1				10
#define SHADER_CONST_LOCALPARAM2				11
#define SHADER_CONST_LOCALPARAM3				12
#define SHADER_CONSTANTBUFFER_OBJECT_SIZE		13




struct SBone
{
	TMatrix4x3		m_boneMatrices[32];		
	
};
typedef SBone VSBone;

#define SHADER_CONST_BLENDMATRIX0				0
#define SHADER_CONST_PREV_BLENDMATRIX0			96
#define SHADER_BLENDMATRIX_SIZE					3
#define SHADER_CONSTANTBUFFER_BONE_SIZE			192




struct SWork
{
	TMatrix4x4		m_viewInverse;		
	TMatrix4x4		m_matrix[8];		
};


struct PSWork
{
	float4			m_vectors[36];
};
typedef SWork VSWork;

#define SHADER_CONST_VIEWINVERSE				0
#define SHADER_CONST_WORKMATRIX0				4
#define SHADER_CONSTANTBUFFER_WORK_SIZE			36




#line 290 "..\Gr\Dg\shader\../DgShaderDefineForDx11Gen.h"


#define TEXUNIT_VOLUMEFOG	TEXUNIT12	// DefferredShadingˆÈ~‚©‚çDraw2D‚Ü‚Å‚ÍŽg‚¤
#define TEXUNIT_DEPTH		TEXUNIT13
#define TEXUNIT_SHADOW		TEXUNIT14



#line 501 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define USE_CONSTANTBUFFER
	

#line 507 "..\Gr\Dg\shader\../DgShaderDefine.h"

#	define PS_REGISTER(_type) REGISTER_B(SHADER_CONSTANTBUFFER_##_type)
#	define VS_REGISTER(_type) REGISTER_B(SHADER_CONSTANTBUFFER_##_type)
#	define REGISTERMAP(_type, _name, _register) cbuffer c##_type : _register { _type _name; }

#line 517 "..\Gr\Dg\shader\../DgShaderDefine.h"


#define SHINESS_NORMALIZE_MAX			256.0
#define SQRT_SHINESS_NORMALIZE_MAX		16.0


#define DG_DRAWPROJECTION_CLIPSPACE_DIRECTX	0
#define DG_DRAWPROJECTION_CLIPSPACE_OPENGL	1








#line 554 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define USE_SPHERICAL_GAUSSIAN_FRESNLE


#line 560 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 564 "..\Gr\Dg\shader\../DgShaderDefine.h"



#line 571 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 577 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define DG_DRAWPROJECTION_CLIPSPACE_TARGET	DG_DRAWPROJECTION_CLIPSPACE_DIRECTX

#line 581 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 586 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 588 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define USE_1002_OPTIMIZE
#define USE_1003_OPTIMIZE


#line 595 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define NOADJUST_DIMMER			//Dimmer‚ðÝ’è‚µ‚Ä‚à‚P‚‚ÌˆÊ’u‚Ì‹P“x‚ª‚©‚í‚ç‚È‚¢‹@”\‚Í‚¢‚ç‚È‚¢



#line 603 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 608 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define DG_HIGH_PRECISION_LACC
	

#line 616 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 620 "..\Gr\Dg\shader\../DgShaderDefine.h"


#line 626 "..\Gr\Dg\shader\../DgShaderDefine.h"



#line 634 "..\Gr\Dg\shader\../DgShaderDefine.h"


#define NORMALMAP_DECODE_DIVZERO_AVOIDANCE

#line 639 "..\Gr\Dg\shader\../DgShaderDefine.h"

#define USE_3RTGBUFFER_PROFILE	//GBUFFER‚R–‡\¬


#define PRIMIRIVE_OUTPUT_MULTI_TARGET		///< k¬ƒoƒbƒtƒ@‚Æƒ}ƒXƒN”²‚«‚Ì®‡«‚ð‚‚ß‚é

#define DRAW2D_BORDER_OLDTYPE				///< ƒtƒHƒ“ƒgƒVƒF[ƒ_‚Ì‰Žæ‚è‚ðˆÈ‘O‚Ì‚Ü‚Ü‚É‚·‚éiŠO‚¹‚ÎV‚µ‚¢ƒ‚[ƒh)



#line 14 "..\Gr\Dg\shader\shader.h"


#define _SHADER_H_


#line 19 "..\Gr\Dg\shader\shader.h"
#define F_TARGET_WINDX11

#line 26 "..\Gr\Dg\shader\shader.h"


#line 30 "..\Gr\Dg\shader\shader.h"


#line 37 "..\Gr\Dg\shader\shader.h"


#define HALF_MIN	(-65504.0)
#define HALF_MAX	(65504.0)



#line 61 "..\Gr\Dg\shader\shader.h"



#line 74 "..\Gr\Dg\shader\shader.h"




#line 86 "..\Gr\Dg\shader\shader.h"



#line 102 "..\Gr\Dg\shader\shader.h"

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


#line 120 "..\Gr\Dg\shader\shader.h"



#line 131 "..\Gr\Dg\shader\shader.h"




#line 140 "..\Gr\Dg\shader\shader.h"

#define DG_SUPPORT_FLEXIBLE_VIEWPORT

#line 144 "..\Gr\Dg\shader\shader.h"



#line 150 "..\Gr\Dg\shader\shader.h"


#define MAX_FILTER_WIDTH   (64)
#define MAX_FILTER_HEIGHT  (64)

#line 155 "..\Gr\Dg\shader\shader.h"


#define RANDOM_TEXTURE_SIZE (32.0)
#define INV_RANDOM_TEXTURE_SIZE (1.0 / 32.0)


#define DECODING_GAMMA  (2.2)

#define ENCODING_GAMMA  (1.0/DECODING_GAMMA)





#define COLOR_ROTATION    (g_psScene.m_shadowProjection)



#define ENABLE_NONDEFERRED_DISTANCE_FADE




#define LUMINANCE_VECTOR  (half3(0.2125h, 0.7154h, 0.0721h))




#define MAX_LUMINANCE (32.0)

#line 190 "..\Gr\Dg\shader\shader.h"

#define HDR_LUM_SCALE ( 16.0h )

#line 193 "..\Gr\Dg\shader\shader.h"

#define USER_TEXCUBELOD	//ƒŠƒtƒŒƒNƒVƒ‡ƒ“ŒvŽZ‚ÉtexCUBElod‚ðŽg‚¤
#define CUBEMAP_BIAS_MAX (5.0H)

#line 200 "..\Gr\Dg\shader\shader.h"

#define LIGHTSCALE_DIFFUSE_TO_SPECULAR (3.1415926H)
#define FWLIGHT_INNER_RANGE (0.5)


#line 207 "..\Gr\Dg\shader\shader.h"






#line 215 "..\Gr\Dg\shader\shader.h"




#line 228 "..\Gr\Dg\shader\shader.h"


#line 235 "..\Gr\Dg\shader\shader.h"
#define CORRECT_TANGNET_VALUE(n) {}

#line 244 "..\Gr\Dg\shader\shader.h"
#define CORRECT_CLONE_TANGNET_VALUE(n) {}

#line 247 "..\Gr\Dg\shader\shader.h"




#line 253 "..\Gr\Dg\shader\shader.h"
#define DG_ENABLE_HALFPIXELOFFSET

#line 256 "..\Gr\Dg\shader\shader.h"

#define PIXELCENTEROFFSET (-0.5)

#line 262 "..\Gr\Dg\shader\shader.h"



#line 272 "..\Gr\Dg\shader\shader.h"

#define ToVPos(vpos) (vpos + PIXELCENTEROFFSET)
#define ToVPos4 ToVPos
#define ToWPos(vpos) (vpos + 0.5f + PIXELCENTEROFFSET)
#define ToWPos4(vpos) ToWPos(vpos)


#line 279 "..\Gr\Dg\shader\shader.h"






#line 285 "..\Gr\Dg\shader\shader.h"

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

#define TFetch3D 								TFetch
#define TFetchCube 								TFetch
#define TFetchCubeBias(_texture, _sampler, _uv) _texture.SampleBias(_sampler, (_uv).xyz, (_uv).w)


#line 326 "..\Gr\Dg\shader\shader.h"
#define TFetchGrad(_texture, _sampler, _uv, _dx, _dy) _texture.SampleGrad(_sampler, _uv, _dx, _dy)
#define TFetch2DLod(_texture, _sampler, _uv) 	_texture.SampleLevel(_sampler, (_uv).xy, (_uv).w)
#define TFetchCubeLod(_texture, _sampler, _uv)	_texture.SampleLevel(_sampler, (_uv).xyz, (_uv).w)

#line 331 "..\Gr\Dg\shader\shader.h"

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


#line 384 "..\Gr\Dg\shader\shader.h"



#line 389 "..\Gr\Dg\shader\shader.h"

half4 packFP16(float2 v)
{
	
    float4 _packed;
    
    
    
	
	
	_packed.xz = frac(256.0*v.xy);
	_packed.yw = _packed.xz * ( -1.0 / 256.0 ) + v.xy ;
    
    return half4(_packed);
}



#line 409 "..\Gr\Dg\shader\shader.h"

half4 packFP32(float v)
{
    
	float4 p = v * float4(1.0, 256.0, (256.0*256.0), (256.0*256.0*256.0));
	return half4(floor(frac(p) * 256.0) * (1.0 / 255.0));
}






float2 unpackFP16(float4 _packed)
{
	const float2 bitSh = float2(1.0/256.0, 1.0);
	float2 _unpacked;
	_unpacked.x = dot(_packed.xy, bitSh);
	_unpacked.y = dot(_packed.zw, bitSh);    
    return _unpacked;
}




float unpackFP32(float4 _packed)
{
	return dot(_packed, float4(
        (255.0/256.0),
        (255.0/(256.0*256.0)),
        (255.0/(256.0*256.0*256.0)),
        (255.0/(256.0*256.0*256.0*256.0))
        ) );
}



#line 448 "..\Gr\Dg\shader\shader.h"

inline half4 WriteSpecularAndVelocity( half2 inSpecular, half2 inVelocity )
{
    half4 outColor ;
    outColor.xy = inSpecular;
    outColor.zw = inVelocity;
    return outColor ;
}



#line 459 "..\Gr\Dg\shader\shader.h"

inline half2 ReadSpecular( half4 inColor )
{
    return inColor.xy ;
}



#line 467 "..\Gr\Dg\shader\shader.h"

inline half2 ReadVelocity( half4 inColor )
{
    return inColor.zw ;
}



#line 475 "..\Gr\Dg\shader\shader.h"

inline half PyramidalDoFMatting( float z, float4 zThresholds )
{
    float z_2 = zThresholds.x ;
    float z_1 = zThresholds.y ;
    float z0  = zThresholds.z ;
    float z1  = zThresholds.w ;
    
    half matting = 1;
    if ( z < z_1 ) {
        matting = (z_1 <= z_2) ? 0 : 
            half( saturate( ( z - z_2 ) / ( z_1 - z_2 ) ) ); 
    } else if ( z > z0 ) {
        matting = half( saturate( ( z1 - z ) / ( z1 - z0 ) ) );
    }
    
    return matting ;
}



#line 501 "..\Gr\Dg\shader\shader.h"

float CalcGlobalVolumetricFogDensity(float3 cameraToWorldPos, float globalDensity, float heightFallOff, float volumetricFogHeightDensityAtViewer)
{
	
	float fogInt = length(cameraToWorldPos) * volumetricFogHeightDensityAtViewer;
	
	
	
	float t = max( heightFallOff * cameraToWorldPos.y, 0.00001 );



		fogInt *= (1.0f - exp(-t)) / t;

	
	return exp(-globalDensity * fogInt);
}
		


#line 525 "..\Gr\Dg\shader\shader.h"


#line 529 "..\Gr\Dg\shader\shader.h"
half GetFresnelSpecularFactor ( half3 halfDir, half3 lightDir, half f0 )
{
	
	half cosValue = half( saturate( dot ( halfDir, lightDir ) ) );
	return f0 + ( 1.0H - f0 ) * (half)exp2 ( ( -5.55473h * cosValue - 6.98316h ) * cosValue );

#line 538 "..\Gr\Dg\shader\shader.h"
}

#line 541 "..\Gr\Dg\shader\shader.h"



#line 547 "..\Gr\Dg\shader\shader.h"

half AdjustLightSizeFromDistance( half size, float dist )
{
	
	

	
	
	
	
	
	return (half)saturate ( size * 1.0H /  dist * 0.9 ) ;
}





#line 572 "..\Gr\Dg\shader\shader.h"

half3 GetReflectionWithRoughness( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2;
	ref_vec2.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );
	ref_vec2 = half4 ( ref_vec2.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	

	
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;

#line 586 "..\Gr\Dg\shader\shader.h"
}



#line 597 "..\Gr\Dg\shader\shader.h"

half3 GetReflection( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	refVec.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );


	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}



#line 615 "..\Gr\Dg\shader\shader.h"

half3 GetReflectionWithRoughness_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2 = half4 ( refVec.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	

	
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;

#line 627 "..\Gr\Dg\shader\shader.h"
}



#line 637 "..\Gr\Dg\shader\shader.h"

half3 GetReflection_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;

	
	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}



#line 654 "..\Gr\Dg\shader\shader.h"

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



#line 683 "..\Gr\Dg\shader\shader.h"

half3 GetBlendColor_Overlay ( half3 baseColor, half3 layerColor, half blendRate )
{
	half3 color0 = baseColor.xyz * layerColor.xyz * 2;	
	half3 color1 = 1.0H - ( 1.0H - baseColor.xyz) * ( 1.0H - layerColor.xyz ) * 2;	
	half3 outColor = select ( baseColor - 0.5H, color0, color1 );
	
	return (half3) lerp ( baseColor.xyz, outColor, blendRate );
}



#line 698 "..\Gr\Dg\shader\shader.h"

half GetCheckerPattern ( half2 uv, half repeat )
{
	half2 checker = (half2)step ( 0.5h, (half2)frac ( uv.xy * repeat ) ) ;
	return ( 1.0h- abs( checker.x - checker.y ) );
}

#define DIRTY_BLEND_AFTER_REFLECTION

half3 BlendDirtyColorSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask )
{
	half3 outColor;
	
	
	
	half3 blend = mask.xyz * dirtyColor.xyz ;
	
	
	half waterScaleBase			 = min ( 0.93H, max (0.73H, (roughness * 255.0H - 205.0H) / 25.0H * (-0.20H) + 0.93H ));
	half waterScaleRoughness	 = min ( 0.66H, (half)saturate ( (roughness * 255.0H - 170.0H) / 60.0H * 0.66H ) );
	
	

	outColor = (half3)lerp ( inColor, inColor * waterScaleBase.xxx, blend.zzz );								
	outColor = (half3)lerp ( outColor, half3 (0.2H, 0.196078431H, 0.192156863H), blend.yyy );					

	outColor = (half3)lerp ( outColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						
	

	outRoughness = (half)lerp ( roughness,	roughness * waterScaleRoughness.x,	blend.z );			
	outRoughness = (half)lerp ( outRoughness,	0.98H,	blend.y );		
	outRoughness = (half)lerp ( outRoughness,	0.2H,	blend.x );		
	
	return outColor;

}
half3 BlendDirtyColorRoughnessMaskSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask, half3 roughnessMask )
{
	half3 outColor;
	
	
	
	half3 blend = mask.xyz * dirtyColor.xyz ;
	half3 blendR = roughnessMask.xyz * dirtyColor.xyz ;
	
	
	half waterScaleBase			 = min ( 0.93H, max (0.73H, (roughness * 255.0H - 205.0H) / 25.0H * (-0.20H) + 0.93H ));
	half waterScaleRoughness	 = min ( 0.66H, (half)saturate ( (roughness * 255.0H - 170.0H) / 60.0H * 0.66H ) );
	
	

	outColor = (half3)lerp ( inColor, inColor * waterScaleBase.xxx, blend.zzz );								
	outColor = (half3)lerp ( outColor, half3 (0.2H, 0.196078431H, 0.192156863H), blend.yyy );					

	outColor = (half3)lerp ( outColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						
	

	outRoughness = (half)lerp ( roughness,	roughness * waterScaleRoughness.x,	blendR.z );			
	outRoughness = (half)lerp ( outRoughness,	0.98H,	blendR.y );		
	outRoughness = (half)lerp ( outRoughness,	0.2H,	blendR.x );		
	
	return outColor;

}



#line 776 "..\Gr\Dg\shader\shader.h"

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
	
	
	half4 dirtyTex = TFetch2DH( dirtyTexture, dirtySampler, texcoord );
	return BlendDirtyColorSub(outRoughness, dirtyTex, inColor, roughness, mask);
}
half3 BlendDirtyColorWithSamplerRoughnessMask ( out half outRoughness, Texture2D dirtyTexture, SamplerState dirtySampler, float2 texcoord, half3 inColor, half roughness, half3 mask, half3 roughnessMask )
{
	
	
	half4 dirtyTex = TFetch2DH( dirtyTexture, dirtySampler, texcoord );
	return BlendDirtyColorRoughnessMaskSub(outRoughness, dirtyTex, inColor, roughness, mask, roughnessMask);
}


half3 BlendDirtyColorRSub ( out half outRoughness, half4 dirtyColor, half3 inColor, half roughness, half3 mask )
{
	half3 outColor;
	
	
	
	half3 blend = mask.xyz * dirtyColor.xyz ;
	
	


	
	

	outColor = (half3)lerp ( inColor, half3 (0.2588H, 0.04705H, 0.043137H), blend.xxx );						
	outRoughness = (half)lerp ( roughness,	0.2H,	blend.x );		
	
	return outColor;

}



#line 834 "..\Gr\Dg\shader\shader.h"

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


#line 848 "..\Gr\Dg\shader\shader.h"


#line 2 "..\Gr\Dg\shader\Common.shdr"


#line 5 "..\Gr\Dg\shader\Common.h"

#define COMMON_H_




#line 36 "..\Gr\Dg\shader\Common.h"



	REGISTERMAP(PSScene,		g_psScene, 			PS_REGISTER( SCENE ));
	REGISTERMAP(PSObject,		g_psObject,			PS_REGISTER( OBJECT ));
	REGISTERMAP(PSLight,		g_psLight, 			PS_REGISTER( LIGHT ));
	REGISTERMAP(PSMaterial,		g_psMaterial, 		PS_REGISTER( MATERIAL ));
	REGISTERMAP(PSWork,			g_psWork, 			PS_REGISTER( WORK ));
	REGISTERMAP(PSSystem,		g_psSystem, 		PS_REGISTER( SYSTEM ));
	
#	ifndef USE_CONSTANTBUFFER
	REGISTERMAP(PSTiling,		g_psTiling, 		PS_REGISTER( TILING ));
#	endif 

#line 53 "..\Gr\Dg\shader\Common.h"


#line 1 "..\Gr\Dg\shader\shadowDefine.h"







#line 13 "..\Gr\Dg\shader\shadowDefine.h"



#line 22 "..\Gr\Dg\shader\shadowDefine.h"




#line 32 "..\Gr\Dg\shader\shadowDefine.h"



#line 41 "..\Gr\Dg\shader\shadowDefine.h"

#define MAX_CASCADE_BLOCKS (4)

#define SHADOW_SUN_SIZE		g_psScene.m_shadowMapResolutions.x
#define SHADOW_CAST1_SIZE 	g_psScene.m_shadowMapResolutions.y
#define SHADOW_CAST2_WIDTH	g_psScene.m_shadowMapResolutions.z
#define SHADOW_CAST2_HEIGHT	g_psScene.m_shadowMapResolutions.w

#line 58 "..\Gr\Dg\shader\shadowDefine.h"



#line 67 "..\Gr\Dg\shader\shadowDefine.h"



#line 55 "..\Gr\Dg\shader\Common.h"



#line 68 "..\Gr\Dg\shader\Common.h"



#line 71 "..\Gr\Dg\shader\Common.h"





#line 76 "..\Gr\Dg\shader\Common.h"

float3 GetEyePosition() {
	return g_psScene.m_eyepos.xyz;
}

#line 81 "..\Gr\Dg\shader\Common.h"



#line 3 "..\Gr\Dg\shader\Common.shdr"


#line 4 "..\Gr\Dg\shader\CoordinateCalculation.h"


#define NEW_VIEWPOS_RECONSTRUCT_CALC



#define ENCODE_NORMAL					// XY‚Ì³‹K‰»AZ‚Ìsqrt‚ð‚Æ‚é”Å





#line 19 "..\Gr\Dg\shader\CoordinateCalculation.h"




#line 25 "..\Gr\Dg\shader\CoordinateCalculation.h"

half4 EncodeViewSpaceNormal( half3 normal )
{
	half4	encodeNormal = 0.0;

#line 30 "..\Gr\Dg\shader\CoordinateCalculation.h"

	encodeNormal.xyz = normal.xyz * 0.5h + 0.5h;
	encodeNormal.z = half(sqrt( half(normal.z) * 0.5h + 0.5h ));

#line 45 "..\Gr\Dg\shader\CoordinateCalculation.h"
	

#line 51 "..\Gr\Dg\shader\CoordinateCalculation.h"

	return encodeNormal ;
}



#line 88 "..\Gr\Dg\shader\CoordinateCalculation.h"





#line 96 "..\Gr\Dg\shader\CoordinateCalculation.h"

half3 DecodeViewSpaceNormal(half4 encodeNormal)
{

#line 107 "..\Gr\Dg\shader\CoordinateCalculation.h"
	

#line 116 "..\Gr\Dg\shader\CoordinateCalculation.h"
	

#line 127 "..\Gr\Dg\shader\CoordinateCalculation.h"
		float bias = 1.0e-007f;

#line 131 "..\Gr\Dg\shader\CoordinateCalculation.h"
		half3	viewSpaceNormal;
		viewSpaceNormal.xy = encodeNormal.xy * 2.0h - 1.0h ;
		viewSpaceNormal.z = ( encodeNormal.z * encodeNormal.z ) * 2.0h - 1.0h ;
		half	oneMinusZz = 1.0h - viewSpaceNormal.z * viewSpaceNormal.z ;
		viewSpaceNormal.xy = ( viewSpaceNormal.xy * oneMinusZz ) * (half)rsqrt( oneMinusZz * (half)dot( viewSpaceNormal.xy, viewSpaceNormal.xy ) + bias );

#line 139 "..\Gr\Dg\shader\CoordinateCalculation.h"


#line 145 "..\Gr\Dg\shader\CoordinateCalculation.h"
	return half3( viewSpaceNormal );
}



#line 154 "..\Gr\Dg\shader\CoordinateCalculation.h"

half3 ReconstructViewSpaceNormal(Texture2D normals, float2 uv)
{
	
	return DecodeViewSpaceNormal(TFetch2DLodH(normals, SamplerPointClamp, float4(uv, 0, 0)));
}

half3 ReconstructViewSpaceNormalWithSampler(Texture2D normals, SamplerState samplerstate, float2 uv)
{
	
	return DecodeViewSpaceNormal(TFetch2DH(normals, samplerstate, uv));
}




#line 188 "..\Gr\Dg\shader\CoordinateCalculation.h"

inline half3 DecodeNormalTexture(half4 color)
{
	half3	normal ;
	

#line 196 "..\Gr\Dg\shader\CoordinateCalculation.h"
    
	

#line 201 "..\Gr\Dg\shader\CoordinateCalculation.h"
	normal.xyz = half3( color.agb ) * 2.0h - 1.0h ;
	
	
	
	
	
	half tmp = half( saturate( 1.0h - normal.x * normal.x - normal.y * normal.y ) + 0.0001h );

#line 213 "..\Gr\Dg\shader\CoordinateCalculation.h"
	normal.z = half( tmp * rsqrt( tmp ) );
	
	
	return normal ;
}



#line 227 "..\Gr\Dg\shader\CoordinateCalculation.h"

inline half3 GetNormalFromTextureWithSampler( Texture2D tex, SamplerState samplerstate, float2 uv )
{
	return DecodeNormalTexture( TFetch2DH( tex, samplerstate, uv ) );
}



#line 238 "..\Gr\Dg\shader\CoordinateCalculation.h"

inline half3 GetNormalFromTexture( Texture2D tex, float2 uv )
{
	return DecodeNormalTexture( TFetch2DH( tex, SamplerLinear, uv ) );
}





#line 251 "..\Gr\Dg\shader\CoordinateCalculation.h"

inline half3 GetNormalFromArrayTexture( Texture3D tex, float3 texcoord )
{
	return DecodeNormalTexture( TFetch3DH( tex, SamplerLinear, texcoord ) ) ;
}


#line 269 "..\Gr\Dg\shader\CoordinateCalculation.h"






#line 278 "..\Gr\Dg\shader\CoordinateCalculation.h"

float4 ReconstructViewPos(float4 clipSpacePos, float4 proj)
{
    float3 viewPos;
    

#line 288 "..\Gr\Dg\shader\CoordinateCalculation.h"
	viewPos.z = proj.z / ( clipSpacePos.z - proj.w ) ;
	viewPos.xy = ( clipSpacePos.xy * proj.xy ) * viewPos.z ;

#line 292 "..\Gr\Dg\shader\CoordinateCalculation.h"

    return float4(viewPos, 1);
}



#line 303 "..\Gr\Dg\shader\CoordinateCalculation.h"

float4 ReconstructViewPosFromTexture(Texture2D inDepth, half2 inTexCoord, float2 clipSpacePosXY,  float4 inProjectionParam)
{

#line 329 "..\Gr\Dg\shader\CoordinateCalculation.h"
	float zOverW = TFetch2DLod(inDepth, SamplerPointClamp, half4(inTexCoord, 0, 0)).x;

#line 335 "..\Gr\Dg\shader\CoordinateCalculation.h"
	
	return ReconstructViewPos( float4(clipSpacePosXY, zOverW, 1),  inProjectionParam );
}



#line 347 "..\Gr\Dg\shader\CoordinateCalculation.h"

float4 ReconstructViewPos2(float2 inScreenSpacePos, float inDepth, float4 inProjectionParam)
{

#line 356 "..\Gr\Dg\shader\CoordinateCalculation.h"


#line 366 "..\Gr\Dg\shader\CoordinateCalculation.h"
	float3	viewPos ;
	viewPos.xy = inScreenSpacePos.xy * inProjectionParam.xy ;
	viewPos.z = inProjectionParam.z / ( inDepth - inProjectionParam.w );

#line 374 "..\Gr\Dg\shader\CoordinateCalculation.h"
	viewPos.xy = viewPos.xy * viewPos.z ;
	return float4( viewPos.xyz, 1 ) ;
}



#line 385 "..\Gr\Dg\shader\CoordinateCalculation.h"

float ReconstructViewZ(float zOverW, float4 proj)
{    

#line 394 "..\Gr\Dg\shader\CoordinateCalculation.h"


#line 397 "..\Gr\Dg\shader\CoordinateCalculation.h"
	return (proj.z / (zOverW - proj.w));
}



#line 408 "..\Gr\Dg\shader\CoordinateCalculation.h"

float ReconstructViewZFromTexture( Texture2D inDepth, float2 inTexCoord, float4 projectionParameter )
{

#line 425 "..\Gr\Dg\shader\CoordinateCalculation.h"
	float zOverW = TFetch2DLod(inDepth, SamplerPointClamp, float4(inTexCoord, 0, 0)).x;

#line 431 "..\Gr\Dg\shader\CoordinateCalculation.h"
	return ReconstructViewZ( zOverW,  projectionParameter );
}


struct DepthBlendResult
{
	float		value;
	float		valueSub;
};

struct PrimitiveDepthFactor
{
	float		viewZ;
	float		viewZSub;
};


void ReconstructViewZFromPrimitiveDepthTexture( Texture2D inDepth, float2 inTexCoord, float4 projectionParameter, out PrimitiveDepthFactor depth )
{

#line 467 "..\Gr\Dg\shader\CoordinateCalculation.h"
	float4 fetchDepth = TFetch2D(inDepth, SamplerPointClamp, inTexCoord);

#line 472 "..\Gr\Dg\shader\CoordinateCalculation.h"
	depth.viewZ = ReconstructViewZ( fetchDepth.x,  projectionParameter );

	{

#line 480 "..\Gr\Dg\shader\CoordinateCalculation.h"
	depth.viewZSub = ReconstructViewZ( fetchDepth.y,  projectionParameter );
	}

#line 484 "..\Gr\Dg\shader\CoordinateCalculation.h"
}

#line 4 "..\Gr\Dg\shader\Common.shdr"





#line 8 "..\Gr\Dg\shader\Common.shdr"


#line 18 "..\Gr\Dg\shader\Common.shdr"




#line 23 "..\Gr\Dg\shader\Common.shdr"


#line 34 "..\Gr\Dg\shader\Common.shdr"




#line 39 "..\Gr\Dg\shader\Common.shdr"


#line 62 "..\Gr\Dg\shader\Common.shdr"



#line 64 "..\Gr\Dg\shader\Common.shdr"


#line 74 "..\Gr\Dg\shader\Common.shdr"




#line 79 "..\Gr\Dg\shader\Common.shdr"


#line 88 "..\Gr\Dg\shader\Common.shdr"



#line 97 "..\Gr\Dg\shader\Common.shdr"



#line 103 "..\Gr\Dg\shader\Common.shdr"


#line 114 "..\Gr\Dg\shader\Common.shdr"




#line 120 "..\Gr\Dg\shader\Common.shdr"


#line 130 "..\Gr\Dg\shader\Common.shdr"




#line 136 "..\Gr\Dg\shader\Common.shdr"


#line 146 "..\Gr\Dg\shader\Common.shdr"




#line 152 "..\Gr\Dg\shader\Common.shdr"


#line 163 "..\Gr\Dg\shader\Common.shdr"




#line 169 "..\Gr\Dg\shader\Common.shdr"


#line 180 "..\Gr\Dg\shader\Common.shdr"




#line 184 "..\Gr\Dg\shader\Common.shdr"


#line 197 "..\Gr\Dg\shader\Common.shdr"



#line 200 "..\Gr\Dg\shader\Common.shdr"


#line 213 "..\Gr\Dg\shader\Common.shdr"



#line 216 "..\Gr\Dg\shader\Common.shdr"




#line 223 "..\Gr\Dg\shader\Common.shdr"


#line 233 "..\Gr\Dg\shader\Common.shdr"




#line 239 "..\Gr\Dg\shader\Common.shdr"


#line 249 "..\Gr\Dg\shader\Common.shdr"




#line 255 "..\Gr\Dg\shader\Common.shdr"


#line 265 "..\Gr\Dg\shader\Common.shdr"




#line 271 "..\Gr\Dg\shader\Common.shdr"


#line 284 "..\Gr\Dg\shader\Common.shdr"




#line 290 "..\Gr\Dg\shader\Common.shdr"


#line 300 "..\Gr\Dg\shader\Common.shdr"





#line 307 "..\Gr\Dg\shader\Common.shdr"


#line 320 "..\Gr\Dg\shader\Common.shdr"


#line 11 "..\Gr\Dg\shader\Primitive.shdr"


#line 7 "..\Gr\Dg\shader\ShadowCommon.h"


#define SHADOWCOMMON_H_

Texture2D g_RandomTexture		: TEXUNIT12 ;


float4 CalcCascadeShadowUVArea( float4x4 shadowParams, float4 view_pos, float4 projection_pos, float4 CascadePlanes[9] )
{
	half   shadowDepth = (half)GetElement( shadowParams, 3, 0); 
	float4 shadow_uv ;    
	
	half3 j1 = half3( (half)(dot( view_pos, CascadePlanes[0] )), (half)(dot( view_pos, CascadePlanes[1] )), (half)(dot( view_pos, CascadePlanes[2] )) );
	half3 j2 = half3( (half)(dot( view_pos, CascadePlanes[3] )), (half)(dot( view_pos, CascadePlanes[4] )), (half)(dot( view_pos, CascadePlanes[5] )) );
	half3 j3 = half3( (half)(dot( view_pos, CascadePlanes[6] )), (half)(dot( view_pos, CascadePlanes[7] )), (half)(dot( view_pos, CascadePlanes[8] )) );
	j1 = 1.0h-(half3)(step(0.99h,abs(j1)));			
	j2 = 1.0h-(half3)(step(0.99h,abs(j2)));
	j3 = 1.0h-(half3)(step(0.99h,abs(j3)));
	half3 mask = half3( j1.x * j1.y * j1.z , j2.x * j2.y * j2.z , j3.x * j3.y * j3.z );
	
	half4 final_mask = half4( mask.x, mask.y * (1 - mask.x) , mask.z * (1 - mask.y),  1-step(1,mask.x+mask.y+mask.z)  );
	float4	scale_vec ;
	scale_vec = ApplyMatrixT( shadowParams, float4( (float3)final_mask.yzw, 0 ) );
	scale_vec.w += (float)(1.0h * final_mask.x);
	shadow_uv.xyz = (projection_pos.xyz * scale_vec.w) + scale_vec.xyz ;
	shadow_uv.z = (shadow_uv.z + 1.0) * shadowDepth ;
	
	shadow_uv.xy = shadow_uv.xy * 0.5f + 0.5f;
	shadow_uv.y = 1.0f - shadow_uv.y;
	
	shadow_uv.xy *= 0.5f;
	const half4x4 cascadeOffset = { 
		0,0.5h,    0,0.5h,
		0,0    ,0.5h,0.5h,
		0,0,        0,     0,
		0,0,        0,     0,
	};
	half2 selectedOffset = (half2)ApplyMatrixT( cascadeOffset, final_mask.xyzw );
	shadow_uv.xy += (half2)selectedOffset;
	shadow_uv.w = 1;				
	return shadow_uv ;
}



#line 57 "..\Gr\Dg\shader\ShadowCommon.h"

float4 CalcCascadeShadowUV( float4x4 shadowParams, float4 projection_pos, float invRangeIntervalLog )
{
	float  shadowDepth 			= GetElement( shadowParams, 3, 0); 

#line 91 "..\Gr\Dg\shader\ShadowCommon.h"
	
	const float   SHADOW_TEXTURE_UV_AREA	= pow( 1.0f - ((1.0 / SHADOW_SUN_SIZE) * 4)  ,2);

	

	
	float4 selected_uv[4];

	selected_uv[0] = float4(projection_pos.xyz,0);

	const float4 lv1Param = GetRowT( shadowParams,0);
	const float4 lv2Param = GetRowT( shadowParams,1);
	const float4 lv3Param = GetRowT( shadowParams,2);

	
	selected_uv[1] = float4( ((projection_pos.xyz * lv1Param.w) + lv1Param.xyz),1);
	selected_uv[2] = float4( ((projection_pos.xyz * lv2Param.w) + lv2Param.xyz),2);
	selected_uv[3] = float4( ((projection_pos.xyz * lv3Param.w) + lv3Param.xyz),3);

	
	selected_uv[0].z = (selected_uv[0].z + 1.0f ) * shadowDepth;
	selected_uv[1].z = (selected_uv[1].z + 1.0f ) * shadowDepth;
	selected_uv[2].z = (selected_uv[2].z + 1.0f ) * shadowDepth;
	selected_uv[3].z = (selected_uv[3].z + 1.0f ) * shadowDepth;

	
	half3 areaJudg1 = half3( step( selected_uv[0].xy * selected_uv[0].xy,SHADOW_TEXTURE_UV_AREA) , step( 0,selected_uv[0].z ) );
	half3 areaJudg2 = half3( step( selected_uv[1].xy * selected_uv[1].xy,SHADOW_TEXTURE_UV_AREA) , step( 0,selected_uv[1].z ) );
	half3 areaJudg3 = half3( step( selected_uv[2].xy * selected_uv[2].xy,SHADOW_TEXTURE_UV_AREA) , step( 0,selected_uv[2].z ) );
	

	
	half4 mask = half4( areaJudg1.x*areaJudg1.y*areaJudg1.z,
					  areaJudg2.x*areaJudg2.y*areaJudg2.z,
					  areaJudg3.x*areaJudg3.y*areaJudg3.z,
					  1 );
	half hit = 1.0h - mask.x;
	mask.y = mask.y * hit;
	hit = hit * (1.0h - mask.y);
	mask.z = mask.z * hit;
	hit = hit * (1.0h - mask.z);
	mask.w = mask.w * hit;

	half4 result = (half4)(
		(selected_uv[0] * mask.x) + 
		(selected_uv[1] * mask.y) + 
		(selected_uv[2] * mask.z) + 
		(selected_uv[3] * mask.w));

	
	result.z = max(0.000001,result.z);
	return result;
}



#line 150 "..\Gr\Dg\shader\ShadowCommon.h"

float4 CalcCascadeShadowUVWithCascadeBlend( float4x4 shadowParams, float4 projection_pos, float invRangeIntervalLog, float2 screenTexCoord )
{

	
	const float	SHADOW_TEXTURE_UV_AREA			 = 1.0f - ((1.0 / SHADOW_SUN_SIZE) * 8);
	const half SHADOW_TEXTURE_UV_AREA_RANDOM_LV0 = (half)(SHADOW_TEXTURE_UV_AREA * SHADOW_TEXTURE_UV_AREA);


#line 159 "..\Gr\Dg\shader\ShadowCommon.h"

	float  useCascadeBlend = GetElement( shadowParams, 3, 3); 

	
	half SHADOW_TEXTURE_UV_AREA_RANDOM_OTH = SHADOW_TEXTURE_UV_AREA_RANDOM_LV0;
	float randomValue = 0;

	if( useCascadeBlend ){
		
		const half2	texCoordCenterOffset = ( (half2)( TFetch2D( g_RandomTexture, SamplerLinear, screenTexCoord * INV_RANDOM_TEXTURE_SIZE ).xy ) );
		
		const float2 INV_SHADOW_SUN_SIZE = (1.0 / SHADOW_SUN_SIZE);
		randomValue = max(texCoordCenterOffset.x,texCoordCenterOffset.y) * 0.0025f;
		SHADOW_TEXTURE_UV_AREA_RANDOM_OTH = 	(half)pow( (SHADOW_TEXTURE_UV_AREA - ((max(texCoordCenterOffset.x,texCoordCenterOffset.y) * SHADOW_SUN_SIZE/4.0h  ) * INV_SHADOW_SUN_SIZE) ) , 2 );
	}


#line 182 "..\Gr\Dg\shader\ShadowCommon.h"


	float  shadowDepth = GetElement( shadowParams, 3, 0); 

	
	float4 selected_uv[4];

	selected_uv[0] = float4(projection_pos.xyz,0);


	const float4 lv1Param = GetRowT( shadowParams,0);
	const float4 lv2Param = GetRowT( shadowParams,1);
	const float4 lv3Param = GetRowT( shadowParams,2);

	
	selected_uv[1] = float4( ((projection_pos.xyz * lv1Param.w) + lv1Param.xyz  ),1);
	selected_uv[2] = float4( ((projection_pos.xyz * lv2Param.w) + lv2Param.xyz  ),2);
	selected_uv[3] = float4( ((projection_pos.xyz * lv3Param.w) + lv3Param.xyz  ),3);

	
	selected_uv[0].z = (selected_uv[0].z + 1.0f ) * shadowDepth;
	selected_uv[1].z = (selected_uv[1].z + 1.0f ) * shadowDepth;
	selected_uv[2].z = (selected_uv[2].z + 1.0f ) * shadowDepth;
	selected_uv[3].z = (selected_uv[3].z + 1.0f ) * shadowDepth;
	
	
	half2 calcAreaUV[4];
	
	
	
	calcAreaUV[0] = (half2)selected_uv[0] * (half2)selected_uv[0];
	calcAreaUV[1] = (half2)selected_uv[1] * (half2)selected_uv[1];
	calcAreaUV[2] = (half2)selected_uv[2] * (half2)selected_uv[2];

#line 218 "..\Gr\Dg\shader\ShadowCommon.h"

	
	half3 areaJudg1 = half3( step( calcAreaUV[0] ,SHADOW_TEXTURE_UV_AREA_RANDOM_LV0) , step( randomValue,selected_uv[0].z ) );
	half3 areaJudg2 = half3( step( calcAreaUV[1] ,SHADOW_TEXTURE_UV_AREA_RANDOM_OTH) , step( randomValue,selected_uv[1].z ) );
	half3 areaJudg3 = half3( step( calcAreaUV[2] ,SHADOW_TEXTURE_UV_AREA_RANDOM_OTH) , step( randomValue,selected_uv[2].z ) );

#line 226 "..\Gr\Dg\shader\ShadowCommon.h"

	
	half4 mask = half4( areaJudg1.x*areaJudg1.y*areaJudg1.z,
					  areaJudg2.x*areaJudg2.y*areaJudg2.z,
					  areaJudg3.x*areaJudg3.y*areaJudg3.z,

#line 233 "..\Gr\Dg\shader\ShadowCommon.h"
					  1 );
	half hit = 1.0h - mask.x;
	mask.y = mask.y * hit;
	hit = hit * (1.0h - mask.y);
	mask.z = mask.z * hit;
	hit = hit * (1.0h - mask.z);
	mask.w = mask.w * hit;

	half4 result = (half4)(
		(selected_uv[0] * mask.x) + 
		(selected_uv[1] * mask.y) + 
		(selected_uv[2] * mask.z) + 
		(selected_uv[3] * mask.w));


#line 253 "..\Gr\Dg\shader\ShadowCommon.h"

	
	result.z = max(0.000001,result.z);
	return result;
}



#line 266 "..\Gr\Dg\shader\ShadowCommon.h"

float4 CalcCascadeShadowUV2( float4x4 shadowParams, float4 projection_pos, float4 projectionParameter )
{
	float4	shadow_uv = projection_pos ;

	
	float depth_scale = GetElement( shadowParams, 3, 0); 

	shadow_uv.z = (shadow_uv.z + 1.0) * depth_scale ;
    
	return shadow_uv ;
}



#line 285 "..\Gr\Dg\shader\ShadowCommon.h"

float4 CalcParaboloidShadowUV(float4 lightParams, float4 view_pos )
{
    
    
    float range_inv = lightParams.z;
    
    float4 position = view_pos;
    
    position = position / position.w;
    
    float isBack = (position.z <= 0.0)?-1.0:1.0;
    position.z *= isBack;
    float len = length(position.xyz);
    position.xyz = position.xyz / len;
    
    position.z = position.z + 1;
    position.xy = position.xy / position.z;
    
    float w = SHADOW_CAST2_WIDTH / 2.0;
    float h = SHADOW_CAST2_HEIGHT;
    position.xy *= float2((w-2.0)/w,(h-2.0)/h);
    
    
    
    position.z = len * range_inv;
    position.z = 1-position.z;


#line 316 "..\Gr\Dg\shader\ShadowCommon.h"

	position.w = isBack;
    
    return position;
}




#line 327 "..\Gr\Dg\shader\ShadowCommon.h"


float ShadowComparisonFiltered( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float attenuation = 1.0)
{
	

#line 341 "..\Gr\Dg\shader\ShadowCommon.h"
	
	float shadow ;


#line 376 "..\Gr\Dg\shader\ShadowCommon.h"
	
	shadow = TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, texCoord.xyzw).x;

#line 388 "..\Gr\Dg\shader\ShadowCommon.h"
	shadow *= attenuation;
	
	shadow = 1.0 - shadow;

	
	
	
	
		
	shadow = shadow*shadow;

	return shadow ;
}



#line 411 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonFourSampleGaussianFilterWithMicroDither( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0 )
{
	float	shadow = 0 ;
	float4 neighbour ;
	float4	offset = float4(0.5,0.5,-0.5,-0.5);
	float2	ditherOffset2x2 = step( float2(0.3,0.3), frac( screenTexCoord.xy / 2.0 ) ) * 2.0 - 1.0 ;
	offset += ditherOffset2x2.xyxy * 0.125 ;
	offset *= texCoord.wwww / shadowMapSize.xyxy ;
	
	neighbour = texCoord;
	neighbour.xy += offset.xy ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	neighbour = texCoord;
	neighbour.xy += offset.zy ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	neighbour = texCoord;
	neighbour.xy += offset.xw ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	neighbour = texCoord;
	neighbour.xy += offset.zw ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	shadow *= 1.0/4.0 ;

	shadow = 1.0 - shadow * attenuation;
	shadow = shadow*shadow;

	return (half)shadow ;
}


#line 451 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonTwoSampleWithDitherGaussianFilter( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0 )
{
	
	float2	ditherOffset2x2 = step( float2(0.3,0.3), frac( screenTexCoord.xy / 2.0 ) ) * 2.0 - 1.0 ;
	float2	offset = float2(0.5,0.5) * ditherOffset2x2.xy / shadowMapSize ;
	float	shadow = 0 ;
	float4 neighbour ;

	neighbour = texCoord;
	neighbour.xy += offset.xy * texCoord.w ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	neighbour = texCoord;
	neighbour.xy -= offset.xy * texCoord.w ;
	shadow += TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, neighbour.xyzw).x;

	shadow *= 1.0/(float)2 ;

	shadow = 1.0 - shadow * attenuation;
	shadow = shadow*shadow;

	return (half)shadow;
}



#line 479 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonFilteredDither( Texture2D shadowMap, float4 baseTexCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0 )
{

#line 485 "..\Gr\Dg\shader\ShadowCommon.h"
	const half2	ditherOffsetScale = half2( 0.25 / shadowMapSize.xy );
	const half2	ditherOffsetOffset = half2( -0.5 * 0.25 / shadowMapSize.xy );
	half2 texCoordCenterOffset = TFetch2DH( g_RandomTexture, SamplerLinear, screenTexCoord * INV_RANDOM_TEXTURE_SIZE ).xy * ditherOffsetScale + ditherOffsetOffset ;
	float4	texCoord = baseTexCoord + float4( texCoordCenterOffset, 0, 0 ) * baseTexCoord.w ;
	half shadow = (half)ShadowComparisonFiltered( shadowMap, texCoord, shadowMapSize, attenuation );
	return shadow ;
}



#line 498 "..\Gr\Dg\shader\ShadowCommon.h"


half GetShadowComparison( Texture2D shadowMap, float4 texCoord )
{
	return (half)TFetch2DProjCmp(shadowMap, SamplerComparisonLessLinear, texCoord.xyzw).x;

#line 523 "..\Gr\Dg\shader\ShadowCommon.h"
}

float ShadowComparisonFilteredRandomFetchFast( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0)
{
	half4 rand 	= TFetch2DH( g_RandomTexture, SamplerLinear, screenTexCoord * INV_RANDOM_TEXTURE_SIZE );
	half2 texCoordCenterOffset = ( (half2)( rand.xy ) - 0.5h ) * 0.35h / (half2)shadowMapSize ;
	texCoord += float4( texCoordCenterOffset, 0.0, 0.0 ) * texCoord.w;	

	half rotOffset = 3.1415926 * rand.z;	
	
	float2 uv;
	float shadow = GetShadowComparison(shadowMap, texCoord.xyzw).x;

	
	for ( int j = 0 ; j < 1 ; j++ ) {
		float4 neighbour = texCoord;
		sincos( 3.1415926/1*j+rotOffset, uv.x, uv.y );
		neighbour.xy += uv.xy / shadowMapSize  * texCoord.w;
		shadow += GetShadowComparison(shadowMap, neighbour.xyzw).x;
	}
	shadow *= ( 1.0/2.0 );
	
	shadow = 1.0 - shadow * attenuation;
	shadow = shadow*shadow;

	return shadow;
}

float ShadowComparisonFilteredRandomFetch( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0)
{
	
	return ShadowComparisonFourSampleGaussianFilterWithMicroDither( shadowMap, texCoord, shadowMapSize, screenTexCoord, attenuation );

#line 580 "..\Gr\Dg\shader\ShadowCommon.h"
}




#line 587 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonFilteredGaussian( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float attenuation = 1.0 )
{

#line 634 "..\Gr\Dg\shader\ShadowCommon.h"
	
#define NUM_SAMPLES (4)
	float2 invShadowMapSize = (1.0 / shadowMapSize);
	float4 offsetPixelSize = float4((invShadowMapSize * 0.3).xx, 0, 0);

	half shadow;
	shadow  = TFetch2DProjCmpH(shadowMap, SamplerComparisonLessLinear, texCoord + (offsetPixelSize * float4(-1, -1, 0, 0))).x;
	shadow += TFetch2DProjCmpH(shadowMap, SamplerComparisonLessLinear, texCoord + (offsetPixelSize * float4( 1, -1, 0, 0))).x;
	shadow += TFetch2DProjCmpH(shadowMap, SamplerComparisonLessLinear, texCoord + (offsetPixelSize * float4(-1,  1, 0, 0))).x;
	shadow += TFetch2DProjCmpH(shadowMap, SamplerComparisonLessLinear, texCoord + (offsetPixelSize * float4( 1,  1, 0, 0))).x;

	shadow *= (half)attenuation;
	
	
	shadow = (1.0h - (shadow * (half)(1.0 / NUM_SAMPLES)));

	
	
	
	
	
	
	shadow = shadow*shadow;

#line 659 "..\Gr\Dg\shader\ShadowCommon.h"

	return shadow ;
}



#line 666 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonFilteredGaussianWithDitherForSun( Texture2D shadowMap, float4 baseTexCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0 )
{
	const float2 INV_SHADOW_SUN_SIZE = (1.0 / SHADOW_SUN_SIZE);


#line 679 "..\Gr\Dg\shader\ShadowCommon.h"
	
	float2	ditherOffset = step( float2(0.3,0.3), frac( screenTexCoord.xy / 2.0 ) ) * 2.0 - 1.0 ;
	float4 texcoord = float4( (baseTexCoord.xy + ditherOffset * 0.125 * INV_SHADOW_SUN_SIZE ) , baseTexCoord.zw );
	
	return ShadowComparisonFilteredGaussian( shadowMap, texcoord, float2( SHADOW_SUN_SIZE, SHADOW_SUN_SIZE ), attenuation );	
}

half ShadowComparisonFilteredGaussianWithDitherForPointSpot( Texture2D shadowMap, float4 baseTexCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0 )
{
	const float2 INV_SHADOW_SIZE = (1.0 / shadowMapSize);


#line 696 "..\Gr\Dg\shader\ShadowCommon.h"
	
	float2	ditherOffset = step( float2(0.3,0.3), frac( screenTexCoord.xy / 2.0 ) ) * 2.0 - 1.0 ;
	float4 texcoord = baseTexCoord.xyzw /= baseTexCoord.w;
	texcoord = float4( (texcoord.xy + ditherOffset * 0.125 * INV_SHADOW_SIZE ) , texcoord.zw );

#line 702 "..\Gr\Dg\shader\ShadowCommon.h"

	return ShadowComparisonFilteredGaussian( shadowMap, texcoord, shadowMapSize, attenuation );	
}




#line 711 "..\Gr\Dg\shader\ShadowCommon.h"

half ShadowComparisonFilteredSunLight( Texture2D shadowMap, float4 baseTexCoord, float2 screenTexCoord, float attenuation = 1.0 )
{
	
	return (half)ShadowComparisonFilteredRandomFetch( shadowMap, baseTexCoord, float2( SHADOW_SUN_SIZE, SHADOW_SUN_SIZE ), screenTexCoord, attenuation );
	

#line 723 "..\Gr\Dg\shader\ShadowCommon.h"
	

#line 729 "..\Gr\Dg\shader\ShadowCommon.h"


#line 735 "..\Gr\Dg\shader\ShadowCommon.h"
	

#line 740 "..\Gr\Dg\shader\ShadowCommon.h"
	
	
}



#line 748 "..\Gr\Dg\shader\ShadowCommon.h"

float ShadowComparisonFilteredPointLight( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0)
{
	return ShadowComparisonFilteredRandomFetch( shadowMap, texCoord, shadowMapSize, screenTexCoord, attenuation );

#line 760 "..\Gr\Dg\shader\ShadowCommon.h"


#line 764 "..\Gr\Dg\shader\ShadowCommon.h"


#line 768 "..\Gr\Dg\shader\ShadowCommon.h"
}



#line 774 "..\Gr\Dg\shader\ShadowCommon.h"

float ShadowComparisonFilteredSpotLight( Texture2D shadowMap, float4 texCoord, const float2 shadowMapSize, float2 screenTexCoord, float attenuation = 1.0)
{
	return ShadowComparisonFilteredRandomFetch( shadowMap, texCoord, shadowMapSize, screenTexCoord, attenuation );
	

#line 784 "..\Gr\Dg\shader\ShadowCommon.h"


#line 788 "..\Gr\Dg\shader\ShadowCommon.h"



#line 793 "..\Gr\Dg\shader\ShadowCommon.h"


#line 797 "..\Gr\Dg\shader\ShadowCommon.h"
}


#line 12 "..\Gr\Dg\shader\Primitive.shdr"


#line 4 "..\Gr\Dg\shader\GammaTransformation.shdr"



#line 4 "..\Gr\Dg\shader\GammaTransformation.h"

#define _GAMMA_TRANSFORMATION_H_


#line 11 "..\Gr\Dg\shader\GammaTransformation.h"

half3 GammaCorrection(float3 linearRGB)
{

#line 24 "..\Gr\Dg\shader\GammaTransformation.h"
	float3 mask = step(linearRGB, 0.0031308);
	return (half3)((mask * (linearRGB * 12.92)) + ((1 - mask) * (1.055 * pow(max(linearRGB, 0.00001), (1.0/2.4)) - 0.055)));
}



#line 35 "..\Gr\Dg\shader\GammaTransformation.h"

float3 GammaDecode(float3 inSRGB)
{

#line 48 "..\Gr\Dg\shader\GammaTransformation.h"
	float3 mask = step(inSRGB, 0.03928);
	return (half3)(mask * (inSRGB / 12.92)) + ((1 - mask) * (pow(max((inSRGB + 0.055)/ 1.055, 0.00001), 2.4)));
}



#line 59 "..\Gr\Dg\shader\GammaTransformation.h"

float GammaDecodeF(float f)
{
    float linear_f;
    linear_f = ((f<=0.03928) ? f/12.92 : pow(abs((f + 0.055)/1.055), 2.4));
    return linear_f;
}


#line 6 "..\Gr\Dg\shader\GammaTransformation.shdr"




#line 9 "..\Gr\Dg\shader\GammaTransformation.shdr"


#line 18 "..\Gr\Dg\shader\GammaTransformation.shdr"




#line 21 "..\Gr\Dg\shader\GammaTransformation.shdr"


#line 30 "..\Gr\Dg\shader\GammaTransformation.shdr"




#line 33 "..\Gr\Dg\shader\GammaTransformation.shdr"


#line 13 "..\Gr\Dg\shader\Primitive.shdr"


#line 31 "..\Gr\Dg\shader\Primitive.h"

#define PRIMITIVE_H_


#line 113 "..\Gr\Dg\shader\Primitive.h"


#line 115 "..\Gr\Dg\shader\Primitive.h"





#line 120 "..\Gr\Dg\shader\Primitive.h"

float GetCurrentExposureValue() { 
	return g_psScene.m_exposure.z;
}


#line 126 "..\Gr\Dg\shader\Primitive.h"

float GetDepthBlendFactor(){
	return g_psObject.m_localParam[2].x;
}



#line 133 "..\Gr\Dg\shader\Primitive.h"

float GetTextureMask(){
	return g_psObject.m_localParam[2].y;
}



#line 140 "..\Gr\Dg\shader\Primitive.h"

float2 GetOutputBufferPixelSize(){
	return g_psObject.m_localParam[2].zw;
}


#line 146 "..\Gr\Dg\shader\Primitive.h"

float4 GetBaseColor(){
	return g_psObject.m_localParam[3].xyzw;
}



#line 153 "..\Gr\Dg\shader\Primitive.h"

half3 GetSunLightDirection(){
	return (half3)g_psObject.m_localParam[0].xyz;
}



#line 160 "..\Gr\Dg\shader\Primitive.h"

half3 GetSunLightColor(){

#line 164 "..\Gr\Dg\shader\Primitive.h"
	return (half3)g_psObject.m_localParam[1].xyz;
}



#line 171 "..\Gr\Dg\shader\Primitive.h"

half3 GetExposureAdjustedSunLightColor(){
	return (half3)(g_psObject.m_localParam[1].xyz * GetCurrentExposureValue());
}



#line 178 "..\Gr\Dg\shader\Primitive.h"

float GetSunLightInverseShadowFadeRange(){
	return g_psLight.m_lightParams[8].x;
}



#line 185 "..\Gr\Dg\shader\Primitive.h"

float GetSunLightNegativeShadowFadeRatio(){
	return g_psLight.m_lightParams[8].y;
}



#line 192 "..\Gr\Dg\shader\Primitive.h"

float GetSunLightShadowIntervalBaseLog(){
	return g_psLight.m_lightParams[8].z;
}



#line 199 "..\Gr\Dg\shader\Primitive.h"

float GetSunLightShadowOffset(){
	return g_psLight.m_lightParams[8].w;
}



#line 206 "..\Gr\Dg\shader\Primitive.h"

float3 GetFirstApproximatedLightPosition(){
	return g_psLight.m_lightParams[2].xyz;
}



#line 213 "..\Gr\Dg\shader\Primitive.h"

float3 GetFirstApproximatedLightColor(){

#line 217 "..\Gr\Dg\shader\Primitive.h"
	return g_psLight.m_lightParams[3].xyz;
}



#line 224 "..\Gr\Dg\shader\Primitive.h"

float GetFirstApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[2].w;
}



#line 231 "..\Gr\Dg\shader\Primitive.h"

float3 GetSecondApproximatedLightPosition(){
	return g_psLight.m_lightParams[4].xyz;
}



#line 238 "..\Gr\Dg\shader\Primitive.h"

float3 GetSecondApproximatedLightColor(){

#line 242 "..\Gr\Dg\shader\Primitive.h"
	return g_psLight.m_lightParams[5].xyz;
}



#line 249 "..\Gr\Dg\shader\Primitive.h"

float GetSecondApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[4].w;
}



#line 256 "..\Gr\Dg\shader\Primitive.h"

float3 GetThirdApproximatedLightPosition(){
	return g_psLight.m_lightParams[6].xyz;
}



#line 263 "..\Gr\Dg\shader\Primitive.h"

float3 GetThirdApproximatedLightColor(){

#line 267 "..\Gr\Dg\shader\Primitive.h"
	return g_psLight.m_lightParams[7].xyz;
}



#line 274 "..\Gr\Dg\shader\Primitive.h"

float GetThirdApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[6].w;
}



#line 281 "..\Gr\Dg\shader\Primitive.h"

float3 GetHemisphereAmbientLightFactor0() {
	return g_psLight.m_lightParams[0].xyz;
}




#line 289 "..\Gr\Dg\shader\Primitive.h"

float3 GetHemisphereAmbientLightFactor1() {
	return g_psLight.m_lightParams[1].xyz;
}


#line 295 "..\Gr\Dg\shader\Primitive.h"




#line 299 "..\Gr\Dg\shader\Primitive.h"

float GetShadowNearRange()
{

#line 304 "..\Gr\Dg\shader\Primitive.h"
	return g_psScene.m_shadowProjection2[3].y;
}


#line 310 "..\Gr\Dg\shader\Primitive.h"

float GetShadowInvBlockUnitRange()
{

#line 315 "..\Gr\Dg\shader\Primitive.h"
	return g_psScene.m_shadowProjection2[3].z;
}



#line 322 "..\Gr\Dg\shader\Primitive.h"

float GetShadowBias()
{

#line 327 "..\Gr\Dg\shader\Primitive.h"
	return g_psScene.m_shadowProjection2[3].w;
}



#line 334 "..\Gr\Dg\shader\Primitive.h"

TMatrix4x4 GetShadowProjectionMatrix()
{

#line 339 "..\Gr\Dg\shader\Primitive.h"
	return g_psScene.m_shadowProjection;
}



#line 346 "..\Gr\Dg\shader\Primitive.h"

TMatrix4x4 GetShadowProjectionMatrix2()
{

#line 351 "..\Gr\Dg\shader\Primitive.h"
	return g_psScene.m_shadowProjection2;
}






#line 361 "..\Gr\Dg\shader\Primitive.h"

half3 CalculateHemisphereAmbinetLight( half3 inNormal ) {
	half3 c0 = (half3)GetHemisphereAmbientLightFactor0() ;
	half3 c1 = (half3)GetHemisphereAmbientLightFactor1() ; 
    
	half fT = (half)dot(inNormal, half3(0, 1, 0));
        
	return ( c0 * fT + c1 ) ;
}



#line 14 "..\Gr\Dg\shader\Primitive.shdr"






#line 40 "..\Gr\Dg\shader\Primitive.shdr"


#line 74 "..\Gr\Dg\shader\Primitive.shdr"





#line 87 "..\Gr\Dg\shader\Primitive.shdr"


#line 121 "..\Gr\Dg\shader\Primitive.shdr"







#line 129 "..\Gr\Dg\shader\Primitive.shdr"


#line 150 "..\Gr\Dg\shader\Primitive.shdr"




#line 156 "..\Gr\Dg\shader\Primitive.shdr"


#line 175 "..\Gr\Dg\shader\Primitive.shdr"





#line 193 "..\Gr\Dg\shader\Primitive.shdr"





#line 206 "..\Gr\Dg\shader\Primitive.shdr"


#line 241 "..\Gr\Dg\shader\Primitive.shdr"



#line 262 "..\Gr\Dg\shader\Primitive.shdr"



#line 274 "..\Gr\Dg\shader\Primitive.shdr"



#line 288 "..\Gr\Dg\shader\Primitive.shdr"





#line 299 "..\Gr\Dg\shader\Primitive.shdr"


#line 352 "..\Gr\Dg\shader\Primitive.shdr"


#line 10 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 1 "..\Fx\Shader\FxCommon.h"




















#line 31 "..\Gr\Dg\shader\Primitive.h"


#line 20 "..\Fx\Shader\FxCommon.h"


#line 3 "..\Gr\Dg\shader\FogVolume.h"




#define GVFOG_VERTICAL_RESOLUTION	( 64.0 )
#define GVFOG_VOLUME_W				( 16.0 )	// volume width
#define GVFOG_VOLUME_H				( 64.0 )	// volume height
#define GVFOG_VOLUME_D				( 128.0 )	// volume depth
#define GVFOG_LAYERS_PER_ROW		( 32.0 )
#define GVFOG_LAYERS_PER_COL		( GVFOG_VOLUME_D / GVFOG_LAYERS_PER_ROW )
#define GVFOG_TEXTURE_W				( GVFOG_LAYERS_PER_ROW * GVFOG_VOLUME_W )	// texture width
#define GVFOG_TEXTURE_H				( GVFOG_LAYERS_PER_COL * GVFOG_VOLUME_H )	// texture height
#define GVFOG_YSCALE				( GVFOG_VERTICAL_RESOLUTION / GVFOG_VOLUME_H )
#define GVFOG_XCLIPSCALE			( 2.0 * GVFOG_VOLUME_W / ( GVFOG_VOLUME_W - 1.0 ) )
#define GVFOG_YCLIPSCALE			( 2.0 * GVFOG_VOLUME_H / ( GVFOG_VOLUME_H - 1.0 ) )
#define GVFOG_USCALE				( 0.5 / GVFOG_LAYERS_PER_ROW - 0.5 / GVFOG_TEXTURE_W )
#define GVFOG_VSCALE				( 0.5 * GVFOG_YSCALE / GVFOG_LAYERS_PER_COL - 0.5 / GVFOG_TEXTURE_H )
#define GVFOG_UOFFSET				( 0.5 / GVFOG_LAYERS_PER_ROW )
#define GVFOG_VOFFSET				( 0.5 * GVFOG_YSCALE / GVFOG_LAYERS_PER_COL )



half EncodeFogCameraZ( float inViewZ )
{
	half invLogFarDistance	= (half)g_psScene.m_fogParam[1].x;

#line 30 "..\Gr\Dg\shader\FogVolume.h"
	return invLogFarDistance * (half)log2(inViewZ);
}



float DecodeFogCameraZ( float inEncodedZ )
{
	float logFarDistance	= 1.0 / g_psScene.m_fogParam[1].x;

#line 42 "..\Gr\Dg\shader\FogVolume.h"
	return exp2( inEncodedZ * logFarDistance );
}


#line 47 "..\Gr\Dg\shader\FogVolume.h"

half4 GetVolumetricFog2D( half2 inClipPos, float inViewZ, Texture2D inFogVolume )
{
	half	zEncoded	= EncodeFogCameraZ( inViewZ ) ;
    zEncoded = (half)saturate( zEncoded );
	zEncoded *= ( GVFOG_VOLUME_D - 1.0h );
	half2	layerPacking= half2(1.0/GVFOG_LAYERS_PER_ROW, 1.0/GVFOG_LAYERS_PER_COL);
	half2	uvScale		= half2( GVFOG_USCALE, GVFOG_VSCALE );
	half2	uvOffset	= half2( GVFOG_UOFFSET, GVFOG_VOFFSET );
	half2	uv = uvScale * (half2)inClipPos + uvOffset ;
	half2	zInt = (half2)floor( float2(zEncoded, clamp( zEncoded + 1, 0, GVFOG_VOLUME_D - 1.0 )) );
	half4 layerOffset;
	layerOffset.xz = (half2) frac( zInt.xy / GVFOG_LAYERS_PER_ROW ) * GVFOG_LAYERS_PER_ROW ;
	layerOffset.yw = (half2) floor( zInt.xy / GVFOG_LAYERS_PER_ROW ) ;
	half4 uv_lerp = uv.xyxy + layerPacking.xyxy * layerOffset.xyzw ;
	half4 zBlend = (half4)frac( zEncoded );
	half4 c0 = TFetch2DH( inFogVolume, SamplerLinearClamp, uv_lerp.xy );
	half4 c1 = TFetch2DH( inFogVolume, SamplerLinearClamp, uv_lerp.zw );
	half4 fogColor = ( 1.0h - zBlend ) * c0 + zBlend * c1 ;

#line 69 "..\Gr\Dg\shader\FogVolume.h"
	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

half4 GetFurthestVolumetricFog2D( half2 inClipPos, Texture2D inFogVolume )
{
	half2	layerPacking= half2(1.0/GVFOG_LAYERS_PER_ROW, 1.0/GVFOG_LAYERS_PER_COL);
	half2	uvScale		= half2( GVFOG_USCALE, GVFOG_VSCALE );
	half2	uvOffset	= half2( GVFOG_UOFFSET, GVFOG_VOFFSET );
	half2	uv = uvScale * (half2)inClipPos + uvOffset ;
	half2	zInt = half2( 127, 127 ); 
	half4 layerOffset;
	layerOffset.xz = (half2) frac( zInt.xy / GVFOG_LAYERS_PER_ROW ) * GVFOG_LAYERS_PER_ROW ;
	layerOffset.yw = (half2) floor( zInt.xy / GVFOG_LAYERS_PER_ROW ) ;
	half2 uv_lerp = uv.xy + layerPacking.xy * layerOffset.xy ;
	half4 fogColor = TFetch2DH( inFogVolume, SamplerLinearClamp, uv_lerp.xy );

#line 90 "..\Gr\Dg\shader\FogVolume.h"
	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

half4 GetVolumetricFog3D( half2 inClipPos, float inViewZ, Texture3D inFogVolume )
{
	half	zEncoded	= EncodeFogCameraZ( inViewZ ) ;
	half3 volCoord = 0;
	volCoord.xy = inClipPos * half2(-0.5,0.5) + half2(0.5,0.5);
	volCoord.z = zEncoded;
	half4 fogColor = (half4)TFetch3D( inFogVolume, SamplerLinearClamp, volCoord.yxz );

#line 106 "..\Gr\Dg\shader\FogVolume.h"
	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

half4 GetFurthestVolumetricFog3D( half2 inClipPos, Texture3D inFogVolume )
{
	float3 volCoord = 1.0; 
	volCoord.xy = inClipPos * float2(-0.5,0.5) + float2(0.5,0.5);
	half4 fogColor = (half4)TFetch3D( inFogVolume, SamplerLinearClamp, volCoord.yxz );

#line 120 "..\Gr\Dg\shader\FogVolume.h"
	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

Texture2D g_tex_fog	: TEXUNIT_VOLUMEFOG;

#line 131 "..\Gr\Dg\shader\FogVolume.h"


#line 137 "..\Gr\Dg\shader\FogVolume.h"

half4 GetVolumetricFog( half2 inClipPos, float inViewZ )
{

#line 142 "..\Gr\Dg\shader\FogVolume.h"
	return GetVolumetricFog2D( inClipPos, inViewZ, g_tex_fog );
}


#line 151 "..\Gr\Dg\shader\FogVolume.h"

half4 GetFurthestVolumetricFog( half2 inClipPos )
{

#line 156 "..\Gr\Dg\shader\FogVolume.h"
	return GetFurthestVolumetricFog2D( inClipPos, g_tex_fog );
}


#line 21 "..\Fx\Shader\FxCommon.h"






#define ENABLE_SOFTWARE_GAMMA_DECODE_TEXTURE	// ƒVƒF[ƒ_“à‚ÅƒKƒ“ƒ}ƒfƒR[ƒh‚ðs‚¤
#define APPLY_PREMULTIPLIED_ALPHA				// æŽZÏ‚ÝƒAƒ‹ƒtƒ@‚Æ‚µ‚ÄŒvŽZ‚ð‚·‚é
#define APPLY_VERTEX_SHADER_EXPOSURE_CORRECT	// ’¸“_ƒVƒF[ƒ_“à‚Å˜Io•â³‚Ì‰e‹¿‚ÌƒXƒP[ƒŠƒ“ƒO‚ð“K—p‚·‚éBƒ‰ƒCƒgŒvŽZ‚Å‚Í—˜—p‚µ‚È‚¢B(half¸“x‚ÅŒvŽZ‚·‚éˆ×j

#line 31 "..\Fx\Shader\FxCommon.h"

#define APPLY_MULTIPLY_VERTEX_COLOR_TO_ALBEDO	// ’¸“_ƒJƒ‰[‚ÌRGB‚ðƒAƒ‹ƒxƒh‚ÌRGB‚ÖæŽZ‚·‚éi‹ŒƒVƒF[ƒ_‚Å‚Ì‚Ý—˜—pj

#define FX_HALF_MAX 65504.0						// half‚ÌÅ‘å’l



#define FX_HALF_MAX_DIV_LIGHT (FX_HALF_MAX/6.0)

#define FxTFetch2DH(_texture, _uv)	TFetch2DH( _texture, SamplerLinear, _uv )
#define FxTFetch2DLodH(_texture, _uv)	TFetch2DLodH( _texture, SamplerLinear, _uv )

#define FX_GBUFFER_TEXTURE_SAMPLER 		SamplerLinear
#define FX_SCREEN_TEXTURE_SAMPLER 		SamplerLinear
#define FX_VOLUMEFOG_TEXTURE_SAMPLER 	SamplerLinear

#define fx_uint uint

#line 52 "..\Fx\Shader\FxCommon.h"

#define FX_ENABLE_RGBA16_BUFFER

#line 56 "..\Fx\Shader\FxCommon.h"









half3 GammaDecode2_2(half3 inSRGB)
{
	return (half3)pow( (float3)max( 0.00001h, inSRGB ), 1.0f / 0.45f );

#line 71 "..\Fx\Shader\FxCommon.h"
}





half3 GammaCorrection2_2(half3 inRGB)
{
   return (half3)pow( (float3)max( 0.00001h, inRGB ), 1.0f / 2.2f );

#line 88 "..\Fx\Shader\FxCommon.h"
}





half4 GetDebugOverDrawModeColor()
{
	return half4(1.0h, 0.5h, 0.15h, 0.2h);	
}

#define BLEND_MODE_ALPHA 	(0.0f)	// ƒuƒŒƒ“ƒhƒ‚[ƒh‚ÍƒAƒ‹ƒtƒ@ƒuƒŒƒ“ƒh
#define BLEND_MODE_ADD 		(1.0f)	// ƒuƒŒƒ“ƒhƒ‚[ƒh‚Í‰ÁŽZƒuƒŒƒ“ƒh







float GetBlendMode()
{
	float param;
	param = GetBaseColor().y;
	return ( param < 0.0f ) ? BLEND_MODE_ADD : BLEND_MODE_ALPHA ;
}


#define TRANSPARENCY_MODE 	(0.0f)	// ”¼“§–¾ƒ‚[ƒh‚Å‚ ‚éŽ–‚ðŽ¦‚·
#define OPAQUE_MODE 		(1.0f)	// •s“§–¾ƒ‚[ƒh‚Å‚ ‚éŽ–‚ðŽ¦‚·







float GetOpaqueMode()
{
	float param;
	param = GetBaseColor().z;
	return ( param < 0.0f ) ? OPAQUE_MODE : TRANSPARENCY_MODE ;
}



float GetCameraFadeInNear()
{
	return abs(GetBaseColor().y);
}




float GetCameraFadeInFar()
{
	return abs(GetBaseColor().z);
}




float GetCameraZOffset()
{
	return GetBaseColor().w;
}


	
#define IS_SPRITE_SHAPE			(1.0f)	// ƒJƒƒ‰‚É‘Î‚µ‚Ä‚’¼‚ÈƒXƒvƒ‰ƒCƒgƒ^ƒCƒv‚Å‚ ‚éŽ–‚ðŽ¦‚·
#define IS_NOT_SPRITE_SHAPE 	(0.0f)	// ƒJƒƒ‰‚É‘Î‚µ‚Ä‚’¼‚Å‚È‚¢ƒXƒvƒ‰ƒCƒgˆÈŠO‚ÌŒ`‚Å‚ ‚éŽ–‚ðŽ¦‚·
	



float IsSpritePolygon()
{
	float param;
	param = GetBaseColor().x;
	return ( param < 0.0f ) ? IS_SPRITE_SHAPE : IS_NOT_SPRITE_SHAPE ;
}



half3 GetCameraEyePosition()
{
	return (half3)GetEyePosition();
}




half3 GetCameraWorldDirection()
{
	

#line 186 "..\Fx\Shader\FxCommon.h"
	return (half3)GetRow(g_psScene.m_view, 2 );
}









#line 199 "..\Fx\Shader\FxCommon.h"





float GetLuminance()
{
	return abs(GetBaseColor().x);
}

float4 GetLuminanceVector()
{
	return float4( GetLuminance().xxx, 1.0f );
}



#line 265 "..\Fx\Shader\FxCommon.h"






#line 435 "..\Fx\Shader\FxCommon.h"




half GetPrecalculatedLuminance(half4 params)
{
	return params.x * params.y;
}
half GetCameraZDistance(half4 params)
{
	return params.z;
}

#line 449 "..\Fx\Shader\FxCommon.h"















struct PointLight
{
	half3 m_lightPosition;	
	half3 m_lightColor;		
	half  m_attenuation;	
};




PointLight GetPointLight0()
{
	PointLight light;

#line 481 "..\Fx\Shader\FxCommon.h"
    light.m_lightPosition = (half3)GetFirstApproximatedLightPosition();
    light.m_lightColor = (half3)(GetFirstApproximatedLightColor() * GetCurrentExposureValue() );
    light.m_attenuation = (half)GetFirstApproximatedLightAttenuationParameter();
	return light;
}




PointLight GetPointLight1()
{
	PointLight light;

#line 499 "..\Fx\Shader\FxCommon.h"
    light.m_lightPosition = (half3)GetSecondApproximatedLightPosition() ;
    light.m_lightColor = (half3)(GetSecondApproximatedLightColor() * GetCurrentExposureValue() );
    light.m_attenuation = (half)GetSecondApproximatedLightAttenuationParameter() ;
	return light;
}




PointLight GetPointLight2()
{
	PointLight light;

#line 517 "..\Fx\Shader\FxCommon.h"
    light.m_lightPosition 	= (half3)GetThirdApproximatedLightPosition();
	light.m_lightColor 		= (half3)(GetThirdApproximatedLightColor() * GetCurrentExposureValue() ); 
	light.m_attenuation 	= (half)GetThirdApproximatedLightAttenuationParameter() ;
	return light;
}













#line 537 "..\Fx\Shader\FxCommon.h"






half2 fxClipPosToTexcoord(half4 projectedPos)
{
	half3 clipPos = (half3)(projectedPos.xyz / projectedPos.w);
	return  half2( clipPos.x, -clipPos.y );
}









half2 fxGetToScreenUVScale()
{
	
	return half2(
		g_psSystem.m_renderInfo.x / g_psSystem.m_renderBuffer.x,
		g_psSystem.m_renderInfo.y / g_psSystem.m_renderBuffer.y );
}





half2 fxGetScreenUVScaleForOnePixel()
{
	half2 scale = fxGetToScreenUVScale();
	return half2( scale.x / g_psScene.m_viewportSize.x, scale.y / g_psScene.m_viewportSize.y );
}

#define FX_REPEAT_START_UV_BASE	(0.995)




half2 fxFetchScreenTextureUVPosMirror(half2 shiftUV, half repeatStartU, half repeatStartV )
{
	
	shiftUV.x = ( shiftUV.x >= repeatStartU ) ? ( repeatStartU - (half)fmod( shiftUV.x, repeatStartU )) : shiftUV.x;
	shiftUV.y = ( shiftUV.y >= repeatStartV ) ? ( repeatStartV - (half)fmod( shiftUV.y, repeatStartV )) : shiftUV.y;
	shiftUV.x = ( shiftUV.x <= 0.0 ) ? ( (half)abs( shiftUV.x )) : shiftUV.x;
	shiftUV.y = ( shiftUV.y <= 0.0 ) ? ( (half)abs( shiftUV.y )) : shiftUV.y;
	return shiftUV;
}





half2 fxFetchScreenTextureUVPosPixelOffset(half4 projectedPos, half2 pixelOffset )
{
	half2 shiftUV = fxClipPosToTexcoord( projectedPos );
	half2 toScreenUV = fxGetToScreenUVScale();
	
	shiftUV = (shiftUV.xy + half2( 1.0, 1.0 )) * half2( 0.5, 0.5 );

	

#line 606 "..\Fx\Shader\FxCommon.h"

	shiftUV = shiftUV * toScreenUV;
	shiftUV += (pixelOffset / 0.5) * fxGetScreenUVScaleForOnePixel();

	
	half repeatStartU = FX_REPEAT_START_UV_BASE * toScreenUV.x;
	half repeatStartV = FX_REPEAT_START_UV_BASE * toScreenUV.y;

	shiftUV = fxFetchScreenTextureUVPosMirror( shiftUV, repeatStartU, repeatStartV );

#line 616 "..\Fx\Shader\FxCommon.h"


	
	
	
	return shiftUV;
}




half CalculateDistortionRate( half inViewZPos, half maxDistortionPixel, half maxDistortionLength )
{
	
	half distortionLength = abs( inViewZPos / maxDistortionLength );
	distortionLength = 1.0 - (half)( saturate( distortionLength ) );
	
	
	half distortionRate = maxDistortionPixel * distortionLength;
    if ( distortionLength <= 0.0 ) {
    	distortionRate = 0.0h;

#line 640 "..\Fx\Shader\FxCommon.h"
    }
	
	return distortionRate;

}









	



half3 CalculatePointLight( 
	float3 inPointLightPosition, 
	float3 inWorldPosition,
	float3 inNormal,
	float3 inEyeDir,
	float3 inLightColor,
	float inAttenuation )
{
	float3 lightDir;
	float innerRange 	= 0.01 ; 
	float dist;
	float d2;
	float att;
	
	float inSpecularPower = 1.0f;
	
	lightDir 	= inPointLightPosition.xyz - inWorldPosition.xyz;
	dist 			= max( length(lightDir), innerRange );
	lightDir = lightDir / dist;
	    
    
    d2 = dist*dist ;
	att = 1.0/d2 - inAttenuation * d2;
	
	half3 outLightDir 	= (half3)lightDir ;
	half3 outLightColor 	= (half3)( inLightColor * max( att, 0 ) );
	
	half	LN, HN ;
	
	
	LN = (half) saturate( dot( outLightDir.xyz, inNormal.xyz ) );
	
	HN = (half) saturate( dot( normalize( outLightDir.xyz - inEyeDir.xyz ), inNormal.xyz ) );

	half4 litV = (half4)lit ( LN, HN, inSpecularPower );
	
	return ((half3)litV.yyy * (half3)outLightColor);
}





half3 CalculatePointLightWrap( 
	PointLight light,
	float3 inWorldPosition,
	float3 inNormal,
	float3 inEyeDir )
{
	return CalculatePointLight(
		light.m_lightPosition,
		inWorldPosition,
		inNormal,
		inEyeDir,
		light.m_lightColor,
		light.m_attenuation );
}





half3 CalculatePointLightDist(
	PointLight pointLight,
	half3 inWorldPosition )
{
	half3 lightDir 	= pointLight.m_lightPosition - inWorldPosition;
	half innerRange 	= 0.01 ; 

	half lightDirLength = (half)length(lightDir);
	

#line 733 "..\Fx\Shader\FxCommon.h"
	
	half dist = (half)max( lightDirLength, innerRange );
	lightDir = lightDir / dist;
	    
    
    half d2 = dist*dist ;

#line 742 "..\Fx\Shader\FxCommon.h"
	half att = 1.0 / d2 - pointLight.m_attenuation * d2;
	
	half3 outColor = (half3)( pointLight.m_lightColor * max( att, 0 ) );
	return outColor;
}









#line 823 "..\Fx\Shader\FxCommon.h"


float fract( float x )
{
	return x - floor(x) ;
}


#line 831 "..\Fx\Shader\FxCommon.h"


#line 853 "..\Fx\Shader\FxCommon.h"






#line 858 "..\Fx\Shader\FxCommon.h"





#line 1 "..\Fx\Shader\FxCommon.shdr"









#line 14 "..\Fx\Shader\FxCommon.shdr"




#line 34 "..\Fx\Shader\FxCommon.shdr"


#line 67 "..\Fx\Shader\FxCommon.shdr"





#line 71 "..\Fx\Shader\FxCommon.shdr"


#line 101 "..\Fx\Shader\FxCommon.shdr"





#line 107 "..\Fx\Shader\FxCommon.shdr"


#line 118 "..\Fx\Shader\FxCommon.shdr"




#line 123 "..\Fx\Shader\FxCommon.shdr"


#line 133 "..\Fx\Shader\FxCommon.shdr"







#line 144 "..\Fx\Shader\FxCommon.shdr"


#line 179 "..\Fx\Shader\FxCommon.shdr"




#line 185 "..\Fx\Shader\FxCommon.shdr"


#line 235 "..\Fx\Shader\FxCommon.shdr"




#line 240 "..\Fx\Shader\FxCommon.shdr"


#line 252 "..\Fx\Shader\FxCommon.shdr"






#line 261 "..\Fx\Shader\FxCommon.shdr"


#line 276 "..\Fx\Shader\FxCommon.shdr"





#line 282 "..\Fx\Shader\FxCommon.shdr"


#line 296 "..\Fx\Shader\FxCommon.shdr"




#line 301 "..\Fx\Shader\FxCommon.shdr"


#line 321 "..\Fx\Shader\FxCommon.shdr"



#line 349 "..\Fx\Shader\FxCommon.shdr"



#line 374 "..\Fx\Shader\FxCommon.shdr"




#line 413 "..\Fx\Shader\FxCommon.shdr"



#line 416 "..\Fx\Shader\FxCommon.shdr"


#line 427 "..\Fx\Shader\FxCommon.shdr"



#line 429 "..\Fx\Shader\FxCommon.shdr"






#line 449 "..\Fx\Shader\FxCommon.shdr"


half3 GammaDecodeIshiyama(half3 inSRGB)
{

#line 455 "..\Fx\Shader\FxCommon.shdr"
	return ( 0.0159964h * inSRGB + 0.668276 * inSRGB * inSRGB + 0.317465 * inSRGB * inSRGB * inSRGB );
}

half3 GammaCorrectionIshiyama(half3 linearRGB)
{

#line 464 "..\Fx\Shader\FxCommon.shdr"
	return (half3)max( 1.05441h * (half3)pow( max( 0.00001h, linearRGB ) ,0.417069h) - 0.0543684h, 0.0h );
}




#line 483 "..\Fx\Shader\FxCommon.shdr"


#line 495 "..\Fx\Shader\FxCommon.shdr"



#line 498 "..\Fx\Shader\FxCommon.shdr"



#line 522 "..\Fx\Shader\FxCommon.shdr"


#line 11 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 1 "..\Gr\Dg\shader\HdrColor.h"
#define HDR_COLOR_H


#line 6 "..\Gr\Dg\shader\HdrColor.h"




#line 12 "..\Gr\Dg\shader\HdrColor.h"

half4 EncodeHDRColor( half3 color )
{
	half4	encodeColor ;

	
	encodeColor.xyz = color.xyz ;
	
	
	encodeColor.w = dot( color.xyz, LUMINANCE_VECTOR * ( 1.0h/HDR_LUM_SCALE ) );

	return encodeColor ;
}



#line 30 "..\Gr\Dg\shader\HdrColor.h"

half3 DecodeHDRColor( half4 encodeColor )
{
	half	scale ;
	half3	color ;

	
	scale = max( 1.0h, encodeColor.w * HDR_LUM_SCALE );
	color.xyz = encodeColor.xyz * scale ;

	return color ;
}


#line 12 "..\Fx\Shader\Prim_Decal_Blood.shdr"



#line 1 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"

#define HDRBUFFER_COMMON_SHDR_


#line 2 "..\Gr\Dg\shader\shader.h"













#line 4 "..\Gr\Dg\shader\../DgShaderDefine.h"




#line 14 "..\Gr\Dg\shader\shader.h"



#line 848 "..\Gr\Dg\shader\shader.h"


#line 5 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"



#line 4 "..\Gr\Dg\shader\AliasHDRColor.h"

#define ALIAS_HDR_COLOR_H_


#line 2 "..\Gr\Dg\shader\shader.h"













#line 4 "..\Gr\Dg\shader\../DgShaderDefine.h"




#line 14 "..\Gr\Dg\shader\shader.h"



#line 848 "..\Gr\Dg\shader\shader.h"


#line 8 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 4 "..\Gr\Dg\shader\GammaTransformation.h"


#line 9 "..\Gr\Dg\shader\AliasHDRColor.h"



#line 95 "..\Gr\Dg\shader\AliasHDRColor.h"

float3	BlendLuv( float3 src, float3 dest )
{
	return float3(
		lerp( dest.rg, src.rg, saturate( (src.b / dest.b) * 0.5f ) ),
		dest.b + src.b
	);
}

const static float3x3 M = float3x3(
  0.2209, 0.3390, 0.4184,
  0.1138, 0.6780, 0.7319,
  0.0102, 0.1130, 0.2969);
const static float3x3 InverseM = float3x3(
  6.0014, -2.7008, -1.7996,
  -1.3320,  3.1029, -5.7721,
  0.3008, -1.0882,  5.6268);

float4 logLuvEncode(in float3 vRGB)  {
  float4 vResult;
  float3 Xp_Y_XYZp = mul(vRGB, M);
  Xp_Y_XYZp = max(Xp_Y_XYZp, float3(1e-6, 1e-6, 1e-6));
  vResult.xy = Xp_Y_XYZp.xy / Xp_Y_XYZp.z;
  float Le = 2 * log2(Xp_Y_XYZp.y) + 127;
  vResult.w = frac(Le);
  vResult.z = (Le - (floor(vResult.w*255.0f))/255.0f)/255.0f;
  return vResult;
}

float3 logLuvDecode(in float4 vLogLuv) {
  float Le = vLogLuv.z * 255 + vLogLuv.w;
  float3 Xp_Y_XYZp;
  Xp_Y_XYZp.y = exp2((Le - 127) / 2);
  Xp_Y_XYZp.z = Xp_Y_XYZp.y / vLogLuv.y;
  Xp_Y_XYZp.x = vLogLuv.x * Xp_Y_XYZp.z;
  float3 vRGB = mul(Xp_Y_XYZp, InverseM);
  return max(vRGB, 0);
}

float4 rgbeEncode(in float3 vRGB)
{
	float fMax = max(max(vRGB.r, vRGB.g), vRGB.b);
	float fExp = floor( log(fMax) / log(1.04) );
	float alpha = clamp(fExp/255.0, 0.0, 1.0);
	vRGB /= pow(1.04, alpha*255.0);
	return float4(vRGB, alpha);
}

float3 rgbeDecode(in float4 vRGBE)
{
	float e = pow(1.04f, vRGBE.a*255.0f);
	vRGBE.rgb *= e;
	return vRGBE.rgb;
}

half4 RGBMEncode( half3 color ) 
{
	half4 rgbm;

	color = (half3)saturate( color * ( 1.0h / 32.0h ) );

	
	
	
	
	

	
	
	
	
	

	
	rgbm.a = (half)dot( color.rgb, half(255.0h/3.0h).xxx );
	rgbm.a = (half)saturate( (half)floor( rgbm.a ) * ( 1.0h / 255.0h ) + ( 1.0h / 255.0h ) );
	rgbm.rgb = color.rgb * (1.0h/3.0h) / rgbm.a;

	
	
	

	return rgbm;
}

half3 RGBMDecode( half4 rgbm ) 
{
	return 32.0h * 3.0h * rgbm.rgb * rgbm.a;
}

half3 SRGBDecode( half4 srgb ) 
{
	return (half3)pow( 2.2, srgb.xyz );
}

half4 SRGBEncode( half3 color ) 
{
	return half4( pow( 0.4545454545454545, color.xyz ) , 1 );
}


#line 214 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 259 "..\Gr\Dg\shader\AliasHDRColor.h"




#line 265 "..\Gr\Dg\shader\AliasHDRColor.h"

half4 EncodeAliasHDRColor(half3 color)
{

#line 269 "..\Gr\Dg\shader\AliasHDRColor.h"
	return half4(color.xyz, 1.0h);

#line 278 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 289 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 300 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 304 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 334 "..\Gr\Dg\shader\AliasHDRColor.h"
}



#line 341 "..\Gr\Dg\shader\AliasHDRColor.h"

half3 DecodeAliasHDRColor( half4 encodedColor )
{

#line 345 "..\Gr\Dg\shader\AliasHDRColor.h"

	
	return encodedColor.xyz;

#line 354 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 356 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 369 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 381 "..\Gr\Dg\shader\AliasHDRColor.h"
	

#line 387 "..\Gr\Dg\shader\AliasHDRColor.h"


#line 419 "..\Gr\Dg\shader\AliasHDRColor.h"
}

half4 EncodeRGBEColor( half3 color )
{
	half4	encodedColor ;
	float3 vRGB = (float3)color;
	encodedColor = (half4)rgbeEncode(vRGB);
	return encodedColor ;
}

half3 DecodeRGBEColor( half4 encodedColor )
{
	float4 vRGBE = (float4)encodedColor;
	half3 color = (half3)rgbeDecode(vRGBE);
	return color ;
}



#line 7 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"



#line 9 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"
#define HDRBUF_ENCODE_DIFFUSE	EncodeAliasHDRColor
#define HDRBUF_DECODE_DIFFUSE	DecodeAliasHDRColor
#define HDRBUF_ENCODE_SPECULAR	EncodeAliasHDRColor
#define HDRBUF_DECODE_SPECULAR	DecodeAliasHDRColor

#line 21 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 35 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 49 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 63 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 77 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"

#define SamplerGBuffer SamplerPoint



#line 85 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 99 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 105 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 152 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 159 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 216 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"






#line 278 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 285 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 311 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 317 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 331 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 337 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 351 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 358 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 386 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"



#line 413 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 420 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 447 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 453 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 466 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"




#line 473 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"


#line 487 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"



#line 14 "..\Fx\Shader\Prim_Decal_Blood.shdr"



#line 4 "..\Gr\Dg\shader\VertexOperation.h"




#line 15 "..\Gr\Dg\shader\VertexOperation.h"

inline void CalculateSkinning( VSBone bones,
							   inout float4 position, float4 blendWeights, uint4 blendIndices,
							   inout float3 normal, inout float3 tangent )
{
	TMatrix4x3		blendMatrix ;
	
	blendMatrix  = bones.m_boneMatrices[ blendIndices.x ] * blendWeights.x ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.y ] * blendWeights.y ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.z ] * blendWeights.z ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.w ] * blendWeights.w ;
	
	position.xyz = ApplyMatrixT( blendMatrix, position.xyzw );
	normal.xyz = ApplyMatrixT( blendMatrix, normal.xyz );
	tangent.xyz = ApplyMatrixT( blendMatrix, tangent.xyz );
	
	normal.xyz = normal.xyz ;	
	tangent.xyz = tangent.xyz ;	
}


#line 43 "..\Gr\Dg\shader\VertexOperation.h"

inline void CalculateSkinning( VSBone bones,
							   inout float4 position, float4 blendWeights, uint4 blendIndices,
							   inout float3 normal )
{
	TMatrix4x3		blendMatrix ;
	
	blendMatrix  = bones.m_boneMatrices[ blendIndices.x ] * blendWeights.x ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.y ] * blendWeights.y ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.z ] * blendWeights.z ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.w ] * blendWeights.w ;
	
	position.xyz = ApplyMatrixT( blendMatrix, position.xyzw );
	normal.xyz = ApplyMatrixT( blendMatrix, normal.xyz );
	
	normal.xyz = normal.xyz ;	
}



#line 69 "..\Gr\Dg\shader\VertexOperation.h"

inline void CalculateSkinningPos( VSBone bones,
							   inout float4 position, float4 blendWeights, uint4 blendIndices )
{
	TMatrix4x3		blendMatrix ;
	
	blendMatrix  = bones.m_boneMatrices[ blendIndices.x ] * blendWeights.x ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.y ] * blendWeights.y ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.z ] * blendWeights.z ;
	blendMatrix += bones.m_boneMatrices[ blendIndices.w ] * blendWeights.w ;
	
	position.xyz = ApplyMatrixT( blendMatrix, position.xyzw );
}



#line 90 "..\Gr\Dg\shader\VertexOperation.h"

inline float4 TransformPosition( VSScene scene, VSObject object,
								 float4 position, out float4 hPosition )
{

#line 117 "..\Gr\Dg\shader\VertexOperation.h"
	float4	onCameraRelative ;
	float3	worldPosition ;
	
	
	
	onCameraRelative = ApplyMatrixT( object.m_viewWorld, position );
	hPosition.xyzw = ApplyMatrixT( scene.m_projection, onCameraRelative.xyzw );
	worldPosition.xyz = ApplyMatrixT( object.m_world, position ).xyz ;
	return float4( worldPosition, 1.0 ) ;
}



#line 138 "..\Gr\Dg\shader\VertexOperation.h"

inline float4 TransformPosition( VSScene scene, VSObject object,
								 float4 position, out float4 hPosition, out float3 viewPosition )
{
	float4	onCameraRelative ;
	float3	worldPosition ;
	
	onCameraRelative = ApplyMatrixT( object.m_viewWorld, position );
	hPosition.xyzw = ApplyMatrixT( scene.m_projection, onCameraRelative.xyzw );
	worldPosition.xyz = ApplyMatrixT( object.m_world, position ).xyz ;
	viewPosition.xyz = onCameraRelative.xyz ;
	return float4( worldPosition, 1.0 ) ;
}

#line 16 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 4 "..\Gr\Dg\shader\ShadowCommon.shdr"




#line 12 "..\Gr\Dg\shader\ShadowCommon.shdr"


#line 29 "..\Gr\Dg\shader\ShadowCommon.shdr"





#line 36 "..\Gr\Dg\shader\ShadowCommon.shdr"


#line 59 "..\Gr\Dg\shader\ShadowCommon.shdr"





#line 66 "..\Gr\Dg\shader\ShadowCommon.shdr"


#line 120 "..\Gr\Dg\shader\ShadowCommon.shdr"






#line 128 "..\Gr\Dg\shader\ShadowCommon.shdr"


#line 152 "..\Gr\Dg\shader\ShadowCommon.shdr"



#line 17 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#define VERTEX_NORMAL_TRANFORM_OFFSET (0.0f)





#line 36 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 103 "..\Fx\Shader\Prim_Decal_Blood.shdr"





#line 111 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 144 "..\Fx\Shader\Prim_Decal_Blood.shdr"






#line 155 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 230 "..\Fx\Shader\Prim_Decal_Blood.shdr"






#line 241 "..\Fx\Shader\Prim_Decal_Blood.shdr"


#line 340 "..\Fx\Shader\Prim_Decal_Blood.shdr"





#line 131 "..\Gr\Dg\shader\Primitive.shdr"
inline void NFetchUV( float2 inVPos, out float2 outUV)
{
#line 139 "..\Gr\Dg\shader\Primitive.shdr"

	float2	pixelSize = GetOutputBufferPixelSize();

#ifdef DG_SHADER_GEN_DX11
	
	const float epsilon = 1.0/256.0;
    outUV = (inVPos.xy + (0.5 - epsilon)) * pixelSize;
#else
	outUV = (inVPos.xy + 0.5.xx) * pixelSize;
#endif

}



#line 179 "..\Gr\Dg\shader\Primitive.shdr"
inline void NComputeDepthComparisonFactor( float inDepth, PrimitiveDepthFactor inSceneDepth, out DepthBlendResult outBlendFactor)
{
#line 188 "..\Gr\Dg\shader\Primitive.shdr"

	outBlendFactor.value = 1.0f;										
	#ifdef PRIMIRIVE_OUTPUT_MULTI_TARGET
	outBlendFactor.valueSub = inDepth <= inSceneDepth.viewZSub ? 1 : 0;	
	#endif
}



#line 243 "..\Gr\Dg\shader\Primitive.shdr"
inline void NOutputColorBufferSoftBlender( DepthBlendResult inZBlendFactor, half3 inColor, half inAlpha, out half4 outColor,  out half4 outColorSub)
{
#line 254 "..\Gr\Dg\shader\Primitive.shdr"


	
	
	outColor    = half4( inColor*(inAlpha*inZBlendFactor.value)    , inAlpha*inZBlendFactor.value );
	#ifdef PRIMIRIVE_OUTPUT_MULTI_TARGET
	outColorSub = half4( inColor*(inAlpha*inZBlendFactor.valueSub) , inAlpha*inZBlendFactor.valueSub);
	#endif
}



#line 264 "..\Gr\Dg\shader\Primitive.shdr"
inline void NGetPrimitiveDepthFactor( float2 inBaseUV, Texture2D inZBuffer, out PrimitiveDepthFactor outDepth)
{
#line 271 "..\Gr\Dg\shader\Primitive.shdr"


	ReconstructViewZFromPrimitiveDepthTexture(inZBuffer,inBaseUV,g_psScene.m_projectionParam,outDepth);
}



#line 284 "..\Fx\Shader\FxCommon.shdr"
inline void NGetGBufferUVPrimitive( half2 inVPos, out half2 outGBufferUV)
{
#line 289 "..\Fx\Shader\FxCommon.shdr"

  	
	half2 screenTextureUV;
	screenTextureUV.x = (half)(inVPos.x / g_psSystem.m_renderInfo.x);
	screenTextureUV.y = (half)(inVPos.y / g_psSystem.m_renderInfo.y);
	screenTextureUV *= fxGetToScreenUVScale();
	outGBufferUV = screenTextureUV;
}



#line 107 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"
inline void NFetchExposuredLAccDiffuse( Texture2D inSampler, float2 inTexcoord, out half3 outColor)
{
#line 116 "..\Gr\Dg\shader\HDRBuffer_Common.shdr"

	half4 encodedDiffuse = TFetch2DH( inSampler, SamplerGBuffer, inTexcoord).xyzw ;

	outColor = HDRBUF_DECODE_DIFFUSE( encodedDiffuse );

#ifdef F_TARGET_WIN32
#ifndef DG_HIGH_PRECISION_LACC
	outColor *= (half)g_psScene.m_exposure.y;
#endif
#endif

#ifdef F_TARGET_XBOXONE
#ifndef DG_HIGH_PRECISION_LACC
	outColor *= (half)g_psScene.m_exposure.y;
#endif
#endif

#ifdef F_TARGET_PS4
#ifndef DG_HIGH_PRECISION_LACC
	outColor *= (half)g_psScene.m_exposure.y;
#endif
#endif


#ifdef F_TARGET_XBOX360
#ifndef LACC_PRECISION_7E3
	outColor *= (half)g_psScene.m_exposure.y;
#endif
#endif
	
	
#ifdef F_TARGET_PS3
#ifndef HIGHPREC_LACC
	outColor *= (half)g_psScene.m_exposure.y;
#endif
#endif
}



#line 157 "..\Fx\Shader\Prim_Decal_Blood.shdr"
inline void NComputePrimitiveColorDecal( half2 inVPos, half4 inColor, half inDepth, half inSceneDepth, half2 inBaseUV, half2 inGBufferUV, half4 inWorldPos, half inShadowRate, half3 inAccumulatedLight, half inNDotPos, TANGENT2WORLD inTangentToWorld, Texture2D inDecalTexture, SamplerState inDecalTextureSampler, Texture2D inNormalTexture, Texture2D inAlbedoBuffer, Texture2D inBackBufferTexture, out half4 outColor)
{
#line 178 "..\Fx\Shader\Prim_Decal_Blood.shdr"



	/*half depthDiff = ( inSceneDepth - inDepth );
	clip( depthDiff - 0.0025f );	// æ‰‹å‰0.0025mä»¥ä¸‹ã§ã‚ã‚Œã°ã€clip*/
	
	
		
	half4 c0 = (half4)TFetch2D(inDecalTexture, inDecalTextureSampler, inBaseUV.xy ) ;
	
	
	half alphaScale = (half)saturate( inNDotPos * ( 1.0h / 0.05h ) );	
	c0.a *= (half)( 1.0h - alphaScale );

	
	half3 albedo = TFetch2DH(inAlbedoBuffer, FX_GBUFFER_TEXTURE_SAMPLER, inGBufferUV).rgb;




	albedo.xyz += ( (half)g_psMaterial.m_materials[1].xxx ); 
	albedo.xyz *= ( (half)g_psMaterial.m_materials[1].yyy + 1.0h ); 

	
	half3 diffuseAlbedoPixel = (half3)( albedo  * inAccumulatedLight.xyz ) ;

	diffuseAlbedoPixel = GammaCorrection(diffuseAlbedoPixel);
	
	half4 backBufferPixel = half4( diffuseAlbedoPixel * c0.rgb * inColor.rgb, 1.0h );
	outColor.rgb = backBufferPixel.rgb;
	outColor.a = c0.a * inColor.a;
	
	outColor.rgb = GammaDecodeIshiyama(outColor.rgb);	
	
	
#ifdef ENABLE_VOLUME_FOG
	// é€šå¸¸ãƒ–ãƒ¬ãƒ³ãƒ‰å›ºå®šï¼ˆåŠ ç®—ã¯ä½¿ã‚ãªã„ï¼‰
	half4 fogColor = CalculateVolumeFogCommon( inVPos, inDepth );
	outColor.rgb = (half3)( outColor.rgb * fogColor.a + fogColor.xyz );
	outColor.a = outColor.a;
#endif
	
	outColor.rgb = GammaCorrectionIshiyama( outColor.rgb );





#ifdef ENABLE_DEBUG_OVER_DRAW_MODE
	outColor = GetDebugOverDrawModeColor();
#endif
	
}







Texture2D	NComputePrimitiveColorDecal_computePrimitiveColor_inBackBufferTexture;
Texture2D	NComputePrimitiveColorDecal_computePrimitiveColor_inAlbedoBuffer;
Texture2D	NComputePrimitiveColorDecal_computePrimitiveColor_inNormalTexture;
SamplerState	NComputePrimitiveColorDecal_computePrimitiveColor_inDecalTextureSampler;
Texture2D	NComputePrimitiveColorDecal_computePrimitiveColor_inDecalTexture;
Texture2D	NGetPrimitiveDepthFactor_fetchViewZ_inZBuffer;
Texture2D	NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_inSampler;
Texture2D	inTexture	:TEXUNIT0 ;
SamplerState	inTextureSampler	:SAMPLERUNIT0 ;
Texture2D	inNormalTexture	:TEXUNIT1 ;
Texture2D	inAlbedoBuffer	:TEXUNIT2 ;
Texture2D	inLightAccDiffuse	:TEXUNIT3 ;
Texture2D	inBackBufferTexture	:TEXUNIT4 ;
Texture2D	inDepthTexture	:TEXUNIT_DEPTH ;
Texture2D	inShadowTexture	:TEXUNIT_SHADOW ;
#line 243 "..\Fx\Shader\Prim_Decal_Blood.shdr"
void ps_main(

	 in	half4	inVPos	: VPOS,
	 in	half2	inBaseUV	: TEXCOORD0,
	 in	half4	inBasePos_NDotPos	: TEXCOORD1,
	 in	half4	inWorldPos	: TEXCOORD2,
	 in	TANGENT2WORLD	inTangentToWorld	: TEXCOORD3,
	 in	half4	inColor	: COLOR0,
	 out	half4	outColor0	: OUT_COLOR0,
	 out	half4	outColor1	: OUT_COLOR1
)
{
	inVPos = ToVPos4( inVPos ) ;
	half2	NGetGBufferUVPrimitive_getGBufferUV_inVPos ;
	half2 NGetGBufferUVPrimitive_getGBufferUV_outGBufferUV ;
#line 290 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NGetGBufferUVPrimitive_getGBufferUV_inVPos = inVPos.xy ;
	NGetGBufferUVPrimitive( NGetGBufferUVPrimitive_getGBufferUV_inVPos, NGetGBufferUVPrimitive_getGBufferUV_outGBufferUV ) ;


		float2	NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_inTexcoord ;
	half3 NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_outColor ;
#line 293 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_inTexcoord = NGetGBufferUVPrimitive_getGBufferUV_outGBufferUV ;
	NFetchExposuredLAccDiffuse( inLightAccDiffuse, NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_inTexcoord, NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_outColor ) ;


	float2	NFetchUV_fetchUV_inVPos ;
	float2 NFetchUV_fetchUV_outUV ;
#line 279 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NFetchUV_fetchUV_inVPos = inVPos.xy ;
	NFetchUV( NFetchUV_fetchUV_inVPos, NFetchUV_fetchUV_outUV ) ;


	float2	NGetPrimitiveDepthFactor_fetchViewZ_inBaseUV ;
		PrimitiveDepthFactor NGetPrimitiveDepthFactor_fetchViewZ_outDepth ;
#line 280 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NGetPrimitiveDepthFactor_fetchViewZ_inBaseUV = NFetchUV_fetchUV_outUV ;
	NGetPrimitiveDepthFactor( NGetPrimitiveDepthFactor_fetchViewZ_inBaseUV, inDepthTexture, NGetPrimitiveDepthFactor_fetchViewZ_outDepth ) ;


	half2	NComputePrimitiveColorDecal_computePrimitiveColor_inVPos ;
	half4	NComputePrimitiveColorDecal_computePrimitiveColor_inColor ;
	half	NComputePrimitiveColorDecal_computePrimitiveColor_inDepth ;
	half	NComputePrimitiveColorDecal_computePrimitiveColor_inSceneDepth ;
	half2	NComputePrimitiveColorDecal_computePrimitiveColor_inBaseUV ;
	half2	NComputePrimitiveColorDecal_computePrimitiveColor_inGBufferUV ;
	half4	NComputePrimitiveColorDecal_computePrimitiveColor_inWorldPos ;
	half	NComputePrimitiveColorDecal_computePrimitiveColor_inShadowRate ;
	half3	NComputePrimitiveColorDecal_computePrimitiveColor_inAccumulatedLight ;
	half	NComputePrimitiveColorDecal_computePrimitiveColor_inNDotPos ;
	TANGENT2WORLD	NComputePrimitiveColorDecal_computePrimitiveColor_inTangentToWorld ;
						half4 NComputePrimitiveColorDecal_computePrimitiveColor_outColor ;
#line 307 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inVPos = inVPos.xy ;
#line 298 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inColor = inColor ;
#line 304 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inDepth = (half)inBasePos_NDotPos.z ;
#line 306 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inSceneDepth = (half)NGetPrimitiveDepthFactor_fetchViewZ_outDepth.viewZ ;
#line 299 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inBaseUV = inBaseUV ;
#line 310 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inGBufferUV = NGetGBufferUVPrimitive_getGBufferUV_outGBufferUV ;
#line 308 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inWorldPos = inWorldPos ;
#line 309 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inShadowRate = 1.0h ;
#line 311 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inAccumulatedLight = NFetchExposuredLAccDiffuse_fetchExposuredLAccDiffuse_outColor ;
#line 305 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inNDotPos = (half)inBasePos_NDotPos.w ;
#line 303 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputePrimitiveColorDecal_computePrimitiveColor_inTangentToWorld = inTangentToWorld ;
	NComputePrimitiveColorDecal( NComputePrimitiveColorDecal_computePrimitiveColor_inVPos, NComputePrimitiveColorDecal_computePrimitiveColor_inColor, NComputePrimitiveColorDecal_computePrimitiveColor_inDepth, NComputePrimitiveColorDecal_computePrimitiveColor_inSceneDepth, NComputePrimitiveColorDecal_computePrimitiveColor_inBaseUV, NComputePrimitiveColorDecal_computePrimitiveColor_inGBufferUV, NComputePrimitiveColorDecal_computePrimitiveColor_inWorldPos, NComputePrimitiveColorDecal_computePrimitiveColor_inShadowRate, NComputePrimitiveColorDecal_computePrimitiveColor_inAccumulatedLight, NComputePrimitiveColorDecal_computePrimitiveColor_inNDotPos, NComputePrimitiveColorDecal_computePrimitiveColor_inTangentToWorld, inTexture, inTextureSampler, inNormalTexture, inAlbedoBuffer, inBackBufferTexture, NComputePrimitiveColorDecal_computePrimitiveColor_outColor ) ;


	float	NComputeDepthComparisonFactor_computeDepthComparisonFactor_inDepth ;
	PrimitiveDepthFactor	NComputeDepthComparisonFactor_computeDepthComparisonFactor_inSceneDepth ;
	DepthBlendResult NComputeDepthComparisonFactor_computeDepthComparisonFactor_outBlendFactor ;
#line 283 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputeDepthComparisonFactor_computeDepthComparisonFactor_inDepth = inBasePos_NDotPos.z ;
#line 284 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NComputeDepthComparisonFactor_computeDepthComparisonFactor_inSceneDepth = NGetPrimitiveDepthFactor_fetchViewZ_outDepth ;
	NComputeDepthComparisonFactor( NComputeDepthComparisonFactor_computeDepthComparisonFactor_inDepth, NComputeDepthComparisonFactor_computeDepthComparisonFactor_inSceneDepth, NComputeDepthComparisonFactor_computeDepthComparisonFactor_outBlendFactor ) ;


	DepthBlendResult	NOutputColorBufferSoftBlender_finalBlender_inZBlendFactor ;
	half3	NOutputColorBufferSoftBlender_finalBlender_inColor ;
	half	NOutputColorBufferSoftBlender_finalBlender_inAlpha ;
	half4 NOutputColorBufferSoftBlender_finalBlender_outColor ;
	half4 NOutputColorBufferSoftBlender_finalBlender_outColorSub ;
#line 330 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NOutputColorBufferSoftBlender_finalBlender_inZBlendFactor = NComputeDepthComparisonFactor_computeDepthComparisonFactor_outBlendFactor ;
#line 331 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NOutputColorBufferSoftBlender_finalBlender_inColor = (half3)NComputePrimitiveColorDecal_computePrimitiveColor_outColor.rgb ;
#line 332 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	NOutputColorBufferSoftBlender_finalBlender_inAlpha = NComputePrimitiveColorDecal_computePrimitiveColor_outColor.a ;
	NOutputColorBufferSoftBlender( NOutputColorBufferSoftBlender_finalBlender_inZBlendFactor, NOutputColorBufferSoftBlender_finalBlender_inColor, NOutputColorBufferSoftBlender_finalBlender_inAlpha, NOutputColorBufferSoftBlender_finalBlender_outColor, NOutputColorBufferSoftBlender_finalBlender_outColorSub ) ;


#line 335 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	outColor0 = NOutputColorBufferSoftBlender_finalBlender_outColor ;

#line 337 "..\Fx\Shader\Prim_Decal_Blood.shdr"
	outColor1 = NOutputColorBufferSoftBlender_finalBlender_outColorSub ;




}
