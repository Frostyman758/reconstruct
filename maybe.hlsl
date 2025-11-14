




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






#define TEXUNIT_VOLUMEFOG	TEXUNIT12	// DefferredShadingï¿½È~ï¿½ï¿½ï¿½ï¿½Draw2Dï¿½Ü‚Å‚ÍŽgï¿½ï¿½
#define TEXUNIT_DEPTH		TEXUNIT13
#define TEXUNIT_SHADOW		TEXUNIT14




#define USE_CONSTANTBUFFER
	


#	define PS_REGISTER(_type) REGISTER_B(SHADER_CONSTANTBUFFER_##_type)
#	define VS_REGISTER(_type) REGISTER_B(SHADER_CONSTANTBUFFER_##_type)
#	define REGISTERMAP(_type, _name, _register) cbuffer c##_type : _register { _type _name; }



#define SHINESS_NORMALIZE_MAX			256.0
#define SQRT_SHINESS_NORMALIZE_MAX		16.0


#define DG_DRAWPROJECTION_CLIPSPACE_DIRECTX	0
#define DG_DRAWPROJECTION_CLIPSPACE_OPENGL	1









#define USE_SPHERICAL_GAUSSIAN_FRESNLE










#define DG_DRAWPROJECTION_CLIPSPACE_TARGET	DG_DRAWPROJECTION_CLIPSPACE_DIRECTX






#define USE_1002_OPTIMIZE
#define USE_1003_OPTIMIZE



#define NOADJUST_DIMMER			//Dimmerï¿½ï¿½ï¿½Ý’è‚µï¿½Ä‚ï¿½ï¿½Pï¿½ï¿½ï¿½ÌˆÊ’uï¿½Ì‹Pï¿½xï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È‚ï¿½ï¿½@ï¿½\ï¿½Í‚ï¿½ï¿½ï¿½ï¿½È‚ï¿½






#define DG_HIGH_PRECISION_LACC
	










#define NORMALMAP_DECODE_DIVZERO_AVOIDANCE


#define USE_3RTGBUFFER_PROFILE	//GBUFFERï¿½Rï¿½ï¿½ï¿½\ï¿½ï¿½


#define PRIMIRIVE_OUTPUT_MULTI_TARGET		///< ï¿½kï¿½ï¿½ï¿½oï¿½bï¿½tï¿½@ï¿½Æƒ}ï¿½Xï¿½Nï¿½ï¿½ï¿½ï¿½ï¿½Ìï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ß‚ï¿½

#define DRAW2D_BORDER_OLDTYPE				///< ï¿½tï¿½Hï¿½ï¿½ï¿½gï¿½Vï¿½Fï¿½[ï¿½_ï¿½Ì‰ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È‘Oï¿½Ì‚Ü‚Ü‚É‚ï¿½ï¿½ï¿½ï¿½iï¿½Oï¿½ï¿½ï¿½ÎVï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½h)





#define _SHADER_H_


#define F_TARGET_WINDX11







#define HALF_MIN	(-65504.0)
#define HALF_MAX	(65504.0)














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










#define DG_SUPPORT_FLEXIBLE_VIEWPORT






#define MAX_FILTER_WIDTH   (64)
#define MAX_FILTER_HEIGHT  (64)



#define RANDOM_TEXTURE_SIZE (32.0)
#define INV_RANDOM_TEXTURE_SIZE (1.0 / 32.0)


#define DECODING_GAMMA  (2.2)

#define ENCODING_GAMMA  (1.0/DECODING_GAMMA)





#define COLOR_ROTATION    (g_psScene.m_shadowProjection)



#define ENABLE_NONDEFERRED_DISTANCE_FADE




#define LUMINANCE_VECTOR  (half3(0.2125h, 0.7154h, 0.0721h))




#define MAX_LUMINANCE (32.0)


#define HDR_LUM_SCALE ( 16.0h )


#define USER_TEXCUBELOD	//ï¿½ï¿½ï¿½tï¿½ï¿½ï¿½Nï¿½Vï¿½ï¿½ï¿½ï¿½ï¿½vï¿½Zï¿½ï¿½texCUBElodï¿½ï¿½ï¿½gï¿½ï¿½
#define CUBEMAP_BIAS_MAX (5.0H)


#define LIGHTSCALE_DIFFUSE_TO_SPECULAR (3.1415926H)
#define FWLIGHT_INNER_RANGE (0.5)














#define CORRECT_TANGNET_VALUE(n) {}

#define CORRECT_CLONE_TANGNET_VALUE(n) {}





#define DG_ENABLE_HALFPIXELOFFSET


#define PIXELCENTEROFFSET (-0.5)





#define ToVPos(vpos) (vpos + PIXELCENTEROFFSET)
#define ToVPos4 ToVPos
#define ToWPos(vpos) (vpos + 0.5f + PIXELCENTEROFFSET)
#define ToWPos4(vpos) ToWPos(vpos)









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


#define TFetchGrad(_texture, _sampler, _uv, _dx, _dy) _texture.SampleGrad(_sampler, _uv, _dx, _dy)
#define TFetch2DLod(_texture, _sampler, _uv) 	_texture.SampleLevel(_sampler, (_uv).xy, (_uv).w)
#define TFetchCubeLod(_texture, _sampler, _uv)	_texture.SampleLevel(_sampler, (_uv).xyz, (_uv).w)


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






half4 packFP16(float2 v)
{
	
    float4 _packed;
    
    
    
	
	
	_packed.xz = frac(256.0*v.xy);
	_packed.yw = _packed.xz * ( -1.0 / 256.0 ) + v.xy ;
    
    return half4(_packed);
}




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




inline half4 WriteSpecularAndVelocity( half2 inSpecular, half2 inVelocity )
{
    half4 outColor ;
    outColor.xy = inSpecular;
    outColor.zw = inVelocity;
    return outColor ;
}




inline half2 ReadSpecular( half4 inColor )
{
    return inColor.xy ;
}




inline half2 ReadVelocity( half4 inColor )
{
    return inColor.zw ;
}




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




float CalcGlobalVolumetricFogDensity(float3 cameraToWorldPos, float globalDensity, float heightFallOff, float volumetricFogHeightDensityAtViewer)
{
	
	float fogInt = length(cameraToWorldPos) * volumetricFogHeightDensityAtViewer;
	
	
	
	float t = max( heightFallOff * cameraToWorldPos.y, 0.00001 );



		fogInt *= (1.0f - exp(-t)) / t;

	
	return exp(-globalDensity * fogInt);
}
		




half GetFresnelSpecularFactor ( half3 halfDir, half3 lightDir, half f0 )
{
	
	half cosValue = half( saturate( dot ( halfDir, lightDir ) ) );
	return f0 + ( 1.0H - f0 ) * (half)exp2 ( ( -5.55473h * cosValue - 6.98316h ) * cosValue );

}





half AdjustLightSizeFromDistance( half size, float dist )
{
	
	

	
	
	
	
	
	return (half)saturate ( size * 1.0H /  dist * 0.9 ) ;
}






half3 GetReflectionWithRoughness( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2;
	ref_vec2.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );
	ref_vec2 = half4 ( ref_vec2.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	

	
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;

}




half3 GetReflection( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, TMatrix4x4 mat  )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	refVec.xyz = (half3) ApplyMatrixT( mat, refVec.xyz );


	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}




half3 GetReflectionWithRoughness_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec, half raghnessRate )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;
	half4 ref_vec2 = half4 ( refVec.xyz, lerp (0, CUBEMAP_BIAS_MAX, 1-raghnessRate) );	

	
	return (half3)TFetchCubeLod( refTex, SamplerLinear, ref_vec2 ).xyz;

}




half3 GetReflection_World( out half3 refVec, TextureCube refTex, half3 viewVec, half3 normalVec )
{
	refVec = (half3) reflect ( viewVec.xyz, normalVec.xyz ) ;

	
	return (half3)TFetchCube( refTex, SamplerLinear, refVec ).xyz;
}




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




half3 GetBlendColor_Overlay ( half3 baseColor, half3 layerColor, half blendRate )
{
	half3 color0 = baseColor.xyz * layerColor.xyz * 2;	
	half3 color1 = 1.0H - ( 1.0H - baseColor.xyz) * ( 1.0H - layerColor.xyz ) * 2;	
	half3 outColor = select ( baseColor - 0.5H, color0, color1 );
	
	return (half3) lerp ( baseColor.xyz, outColor, blendRate );
}




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





// Shared constant buffer bindings and helpers extracted from Common.h so this
// shader can be compiled standalone without additional includes.
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



















#define MAX_CASCADE_BLOCKS (4)

#define SHADOW_SUN_SIZE		g_psScene.m_shadowMapResolutions.x
#define SHADOW_CAST1_SIZE 	g_psScene.m_shadowMapResolutions.y
#define SHADOW_CAST2_WIDTH	g_psScene.m_shadowMapResolutions.z
#define SHADOW_CAST2_HEIGHT	g_psScene.m_shadowMapResolutions.w



















float3 GetEyePosition() {
	return g_psScene.m_eyepos.xyz;
}








#define NEW_VIEWPOS_RECONSTRUCT_CALC



#define ENCODE_NORMAL					// XYï¿½Ìï¿½ï¿½Kï¿½ï¿½ï¿½AZï¿½ï¿½sqrtï¿½ï¿½ï¿½Æ‚ï¿½ï¿½ï¿½










half4 EncodeViewSpaceNormal( half3 normal )
{
	half4	encodeNormal = 0.0;


	encodeNormal.xyz = normal.xyz * 0.5h + 0.5h;
	encodeNormal.z = half(sqrt( half(normal.z) * 0.5h + 0.5h ));

	


	return encodeNormal ;
}









half3 DecodeViewSpaceNormal(half4 encodeNormal)
{

	

	

		float bias = 1.0e-007f;

		half3	viewSpaceNormal;
		viewSpaceNormal.xy = encodeNormal.xy * 2.0h - 1.0h ;
		viewSpaceNormal.z = ( encodeNormal.z * encodeNormal.z ) * 2.0h - 1.0h ;
		half	oneMinusZz = 1.0h - viewSpaceNormal.z * viewSpaceNormal.z ;
		viewSpaceNormal.xy = ( viewSpaceNormal.xy * oneMinusZz ) * (half)rsqrt( oneMinusZz * (half)dot( viewSpaceNormal.xy, viewSpaceNormal.xy ) + bias );



	return half3( viewSpaceNormal );
}




half3 ReconstructViewSpaceNormal(Texture2D normals, float2 uv)
{
	
	return DecodeViewSpaceNormal(TFetch2DLodH(normals, SamplerPointClamp, float4(uv, 0, 0)));
}

half3 ReconstructViewSpaceNormalWithSampler(Texture2D normals, SamplerState samplerstate, float2 uv)
{
	
	return DecodeViewSpaceNormal(TFetch2DH(normals, samplerstate, uv));
}





inline half3 DecodeNormalTexture(half4 color)
{
	half3	normal ;
	

    
	

	normal.xyz = half3( color.agb ) * 2.0h - 1.0h ;
	
	
	
	
	
	half tmp = half( saturate( 1.0h - normal.x * normal.x - normal.y * normal.y ) + 0.0001h );

	normal.z = half( tmp * rsqrt( tmp ) );
	
	
	return normal ;
}




inline half3 GetNormalFromTextureWithSampler( Texture2D tex, SamplerState samplerstate, float2 uv )
{
	return DecodeNormalTexture( TFetch2DH( tex, samplerstate, uv ) );
}




inline half3 GetNormalFromTexture( Texture2D tex, float2 uv )
{
	return DecodeNormalTexture( TFetch2DH( tex, SamplerLinear, uv ) );
}






inline half3 GetNormalFromArrayTexture( Texture3D tex, float3 texcoord )
{
	return DecodeNormalTexture( TFetch3DH( tex, SamplerLinear, texcoord ) ) ;
}









float4 ReconstructViewPos(float4 clipSpacePos, float4 proj)
{
    float3 viewPos;
    

	viewPos.z = proj.z / ( clipSpacePos.z - proj.w ) ;
	viewPos.xy = ( clipSpacePos.xy * proj.xy ) * viewPos.z ;


    return float4(viewPos, 1);
}




float4 ReconstructViewPosFromTexture(Texture2D inDepth, half2 inTexCoord, float2 clipSpacePosXY,  float4 inProjectionParam)
{

	float zOverW = TFetch2DLod(inDepth, SamplerPointClamp, half4(inTexCoord, 0, 0)).x;

	
	return ReconstructViewPos( float4(clipSpacePosXY, zOverW, 1),  inProjectionParam );
}




float4 ReconstructViewPos2(float2 inScreenSpacePos, float inDepth, float4 inProjectionParam)
{



	float3	viewPos ;
	viewPos.xy = inScreenSpacePos.xy * inProjectionParam.xy ;
	viewPos.z = inProjectionParam.z / ( inDepth - inProjectionParam.w );

	viewPos.xy = viewPos.xy * viewPos.z ;
	return float4( viewPos.xyz, 1 ) ;
}




float ReconstructViewZ(float zOverW, float4 proj)
{    



	return (proj.z / (zOverW - proj.w));
}




float ReconstructViewZFromTexture( Texture2D inDepth, float2 inTexCoord, float4 projectionParameter )
{

	float zOverW = TFetch2DLod(inDepth, SamplerPointClamp, float4(inTexCoord, 0, 0)).x;

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

	float4 fetchDepth = TFetch2D(inDepth, SamplerPointClamp, inTexCoord);

	depth.viewZ = ReconstructViewZ( fetchDepth.x,  projectionParameter );

	{

	depth.viewZSub = ReconstructViewZ( fetchDepth.y,  projectionParameter );
	}

}






























































































































half3 GetTonemapedColor_Filmic(half3 color)
{
	half3 x = max(0, (color - 0.004h));
	return (x *((6.2h * x)+ 0.5h)) / ((x *((6.2h * x)+ 1.7h))+ 0.06h);
}




half3 getTonemapedColor_UnchartedFilmic(half3 color, half a, half b, half c, half d, half e, half f)
{
    return ((color * ((a * color) + (c * b)) + (d * e)) / (color * ((a * color) + b) + (d * f))) - (e / f);
}




half3 GetTonemapedColor_UnchartedFilmic(half3 color, half w, half a, half b, half c, half d, half e, half f)
{
	half3 invTonemapedWhite = (1.0 / getTonemapedColor_UnchartedFilmic(w, a, b, c, d, e, f));
	return getTonemapedColor_UnchartedFilmic(color, a, b, c, d, e, f) * invTonemapedWhite;
}






#define M_PI 	(3.141592654)

#define TRANSMITTANCE_W (256)	// Transmittanceãƒ†ã‚¯ã‚¹ãƒãƒ£ã®æ¨ªå¹…
#define TRANSMITTANCE_H (64)	// Transmittanceãƒ†ã‚¯ã‚¹ãƒãƒ£ã®ç¸¦å¹…

#define IRRADIANCE_W	(64)	// Irradianceãƒ†ã‚¯ã‚¹ãƒãƒ£ã®æ¨ªå¹…
#define IRRADIANCE_H	(16)	// Irradianceãƒ†ã‚¯ã‚¹ãƒãƒ£ã®ç¸¦å¹…


#define RES_R		(16)		// Inscatteringãƒ†ã‚¯ã‚¹ãƒãƒ£ã® r ã«å¯¾ã™ã‚‹è§£åƒåº¦


#define RES_MU 		(128)		// Inscatteringãƒ†ã‚¯ã‚¹ãƒãƒ£ã® Î¼ ã«å¯¾ã™ã‚‹è§£åƒåº¦
#define RES_MU_S	(32)		// Inscatteringãƒ†ã‚¯ã‚¹ãƒãƒ£ã® Î¼s ã«å¯¾ã™ã‚‹è§£åƒåº¦
#define RES_NU		(8)			// Inscatteringãƒ†ã‚¯ã‚¹ãƒãƒ£ã® Î½ ã«å¯¾ã™ã‚‹è§£åƒåº¦

#define Rg 		(6360.0)		// æƒ‘æ˜Ÿã®åœ°è¡¨ã¾ã§ã®åŠå¾„(km)
#define Rt 		(6420.0)		// æƒ‘æ˜Ÿã®å¤§æ°—åœã¾ã§ã®åŠå¾„(km)
#define RL 		(6421.0)		// æƒ‘æ˜Ÿã®å¤§æ°—åœã¾ã§ã®åŠå¾„ã®å¤–(km)




#define EXTRACTED_TRANSMITTANCE_W	(256)
#define EXTRACTED_TRANSMITTANCE_H	(16)
#define EXTRACTED_RES_R			(4)
#define EXTRACTED_RES_MU 		(64)
#define EXTRACTED_RES_MU_S		(16)
#define EXTRACTED_RES_NU		(8)




#define AVERAGE_GROUND_REFLECTANCE (0.1)
 



#define TRANSMITTANCE_INTEGRAL_SAMPLES 			(50) 	// (500)	// (g_psMaterial.m_materials[3].x)
#define IRRADIANCE_INTEGRAL_SAMPLES 			(16) 	// (32) 	// (g_psMaterial.m_materials[3].y)
#define INSCATTER_INTEGRAL_SAMPLES 				(12)	// (50)		// (g_psMaterial.m_materials[3].z)
#define INSCATTER_SPHERICAL_INTEGRAL_SAMPLES	(8) 	// (16)		// (g_psMaterial.m_materials[3].w)	


#define FAKE_BACKGROUND_COLOR  (float3(0.003284, 0.00411, 0.006240))

float absSqrt(float value)
{
	return sqrt(max(0, value));
}




float limit(float r, float mu) 
{
    float dout 		= -r * mu + absSqrt(r * r * (mu * mu - 1.0) + RL * RL);
    float delta2 	= r * r * (mu * mu - 1.0) + Rg * Rg;
    
    if (delta2 >= 0.0) 
    {
        float din = -r * mu - sqrt(delta2);
        
        if (din >= 0.0) 
        {
            dout = min(dout, din);
        }
    }
    return dout;
}



void getTransmittanceRMu(float2 vpos, out float r, out float muS)
{	
    muS	= (vpos.x) / float(TRANSMITTANCE_W);
	r 	= (vpos.y) / float(TRANSMITTANCE_H);
    
	muS = -0.15 + tan(1.5 * muS) / tan(1.5) * (1.0 + 0.15);
	r 	= Rg + (r * r) * (Rt - Rg);
}



void getIrradianceRMuS(float2 vpos, out float r, out float mu) 
{
    mu	= -0.2 + (vpos.x - 0.5f) / (float(IRRADIANCE_W) - 1.0) * (1.0 + 0.2);
    r 	=   Rg + (vpos.y - 0.5f) / (float(IRRADIANCE_H) - 1.0) * (Rt - Rg);
}



void getMuMuSNu(float2 vpos, float r, float4 dhdH, out float mu, out float muS, out float nu) 
{
    float x = (vpos.x);
    
    float y = fmod(vpos.y, float(RES_MU));
    
    x = max(x, 0.0);
    
    if (y < float(RES_MU) / 2.0) 
    {
        float d = 1.0 - y / (float(RES_MU) / 2.0 - 1.0);
        
        d 	= min(max(dhdH.z, d * dhdH.w), dhdH.w * 0.999);
        mu 	= (Rg * Rg - r * r - d * d) / (2.0 * r * d);
        mu 	= min(mu, -absSqrt(1.0 - (Rg / r) * (Rg / r)) - 0.001);
    } 
    else 
    {
        float d = (y - float(RES_MU) / 2.0) / (float(RES_MU) / 2.0 - 1.0);
        
        d 	= min(max(dhdH.x, d * dhdH.y), dhdH.y * 0.999);
        mu 	= (Rt * Rt - r * r - d * d) / (2.0 * r * d);
    }
    
    
    
    
    
    
    muS = fmod(x, float(RES_MU_S)) / float(RES_MU_S);
    
    
    
    
    muS = tan((2.0 * muS - 1.0 + 0.26) * 1.1) / tan(1.26 * 1.1);
    nu 	= -1.0 + floor(x / float(RES_MU_S)) / (float(RES_NU) - 1.0) * 2.0;

}


void getLayer(float2 vpos, out float layer)
{
	
	layer = floor((vpos.y)/float(RES_MU));
}


void getRDhdHLayer(float2 vpos, out float r, out float4 dhdH, out float layer)
{
	getLayer(vpos, layer);


	r = layer / (float(RES_R) - 1.0);
	r = r * r;
	r = sqrt( Rg*Rg + r*(Rt*Rt-Rg*Rg)) + (layer==0 ? 0.01f : (layer==RES_R-1 ? -0.001f : 0.0f));
	dhdH = float4( 	(Rt - r),
					(absSqrt(r*r-Rg*Rg) + absSqrt(Rt*Rt-Rg*Rg)),
					(r - Rg),
					(absSqrt(r*r-Rg*Rg)));
}


void getRDhdH(float2 vpos, out float r, out float4 dhdH)
{
	float layer;
	getRDhdHLayer(vpos, r, dhdH, layer);
}




float getOpticalDepth(float H, float r, float mu)
{
    float result = 0.0;
    
    float dx = limit(r, mu) / float(TRANSMITTANCE_INTEGRAL_SAMPLES);
    float xi = 0.0;
    float yi = exp(-(r - Rg) / H);
    
    [loop]
    for (int i=1; i<=TRANSMITTANCE_INTEGRAL_SAMPLES; ++i) 
    {
        float xj = float(i) * dx;
        float yj = exp(-(sqrt(r * r + xj * xj + 2.0 * xj * r * mu) - Rg) / H);
        result += (yi + yj) / 2.0 * dx;
        xi = xj;
        yi = yj;
    }
    
    return mu < -absSqrt(1.0 - (Rg / r) * (Rg / r)) ? 1e9 : result;
}





float opticalDepth(float H, float r, float mu, float d) 
{
    float a 		= sqrt((0.5/H)*r);
    float2 a01 		= a*float2(mu, mu + d / r);
    float2 a01s 	= sign(a01);
    float2 a01sq 	= a01*a01;
    float x 		= a01s.y > a01s.x ? exp(a01sq.x) : 0.0;
    float2 y 		= a01s / (2.3193*abs(a01) + sqrt(1.52*a01sq + 4.0)) * float2(1.0, exp(-d/H*(d/(2.0*r)+mu)));
    
    return sqrt((6.2831*H)*r) * exp((Rg-r)/H) * (x + dot(y, float2(1.0, -1.0)));
}

	


float phaseFunctionR(float mu) 
{
    return (3.0 / (16.0 * M_PI)) * (1.0 + mu * mu);
}



float phaseFunctionR_Half( const half mu )
{
    return (3.0 / (16.0 * M_PI)) * (1.0 + mu * mu);
}



float phaseFunctionM(float mu, float mieG) 
{
	return 1.5 * 1.0 / (4.0 * M_PI) * (1.0 - mieG*mieG) * pow(abs(1.0 + (mieG*mieG) - 2.0*mieG*mu), -3.0/2.0) * (1.0 + mu * mu) / (2.0 + mieG*mieG);
	
}




float4 textureFake3D(Texture2D table, float3 uvw)
{	
	return TFetch2D(table, SamplerLinearClamp, uvw.xy);
}



float4 texture4D(Texture2D table, float r, float mu, float muS, float nu)
{
    const float H 		= absSqrt(Rt * Rt - Rg * Rg);
    const float rho 	= absSqrt(r * r - Rg * Rg);
    const float rmu 	= r * mu;
    const float delta 	= rmu * rmu - r * r + Rg * Rg;
    
	float4 cst 	= ((rmu<0.0f)&&(delta>0.0f)) ? float4(1.0f, 0.0f, 0.0f, 0.5f - 0.5f / float(RES_MU)) : float4(-1.0f, H * H, H, 0.5f + 0.5f / float(RES_MU));

	float uR 	= 0.5f / float(RES_R) + rho / H * (1.0f - 1.0f / float(RES_R));
  	float uMu 	= cst.w + (cst.x * rmu + sqrt(delta + cst.y)) / (rho + cst.z) * (0.5f - 1.0f / float(RES_MU));
	
    
    
    
    float uMuS 	= 0.5f / float(RES_MU_S) + (atan(max(muS, -0.1975f) * tan(1.26f * 1.1f)) / 1.1f + (1.0f - 0.26f)) * 0.5f * (1.0f - 1.0f / float(RES_MU_S));
    
	float lerp1 	= (nu + 1.0f) / 2.0f * (float(RES_NU) - 1.0f);
    float uNu 	= floor(lerp1);
    lerp1 		= lerp1 - uNu;

	
	float lerp2 = uR*(RES_R-1.0f);
	lerp2 		= lerp2 - floor(uR*(RES_R-1.0f));

	
	float2 uv1 = float2( (uNu + uMuS)		/ float(RES_NU), (uMu + floor(uR*(float(RES_R)-1.0f)) ) / float(RES_R) );
	float2 uv2 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(RES_R)-1.0f)) ) / float(RES_R) );

	float2 uv3 = float2( (uNu + uMuS) 		/ float(RES_NU), (uMu + floor(uR*(float(RES_R)-1.0f)) + 1.0f) / float(RES_R) );
	float2 uv4 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(RES_R)-1.0f)) + 1.0f) / float(RES_R) );

	float4 color 	= TFetch2D(table, SamplerLinearClamp, uv1) * (1.0f-lerp1) + TFetch2D(table, SamplerLinearClamp, uv2) * lerp1;
	float4 color2 	= TFetch2D(table, SamplerLinearClamp, uv3) * (1.0f-lerp1) + TFetch2D(table, SamplerLinearClamp, uv4) * lerp1;

	color = lerp(color, color2, lerp2);

    return color;
}

half4 texture4D_Half(Texture2D table, float r, const half mu, const half muS, const half nu)
{
	const float H 		= absSqrt(Rt * Rt - Rg * Rg);
	const float rho 	= absSqrt(r * r - Rg * Rg);
	const float rmu 	= r * mu;
	const float delta 	= rmu * rmu - r * r + Rg * Rg;

	float4 cst 	= ((rmu<0.0f)&&(delta>0.0f)) ? float4(1.0f, 0.0f, 0.0f, 0.5f - 0.5f / float(RES_MU)) : float4(-1.0f, H * H, H, 0.5f + 0.5f / float(RES_MU));

	float uR 	= 0.5f / float(RES_R) + rho / H * (1.0f - 1.0f / float(RES_R));
	float uMu 	= cst.w + (cst.x * rmu + sqrt(delta + cst.y)) / (rho + cst.z) * (0.5f - 1.0f / float(RES_MU));

	
	
	
	float uMuS 	= 0.5f / float(RES_MU_S) + (atan(max(muS, -0.1975f) * tan(1.26f * 1.1f)) / 1.1f + (1.0f - 0.26f)) * 0.5f * (1.0f - 1.0f / float(RES_MU_S));

	float lerp1 	= (nu + 1.0f) / 2.0f * (float(RES_NU) - 1.0f);
	float uNu 	= floor(lerp1);
	lerp1 		= lerp1 - uNu;

	uR		= saturate( uR * ( RES_R / EXTRACTED_RES_R ) );

	
	float lerp2 = uR*(EXTRACTED_RES_R-1.0f);
	lerp2 		= lerp2 - floor(uR*(EXTRACTED_RES_R-1.0f));
	
	float2 uv1 = float2( (uNu + uMuS)		/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) ) / float(EXTRACTED_RES_R) );
	float2 uv2 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) ) / float(EXTRACTED_RES_R) );

	float2 uv3 = float2( (uNu + uMuS) 		/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) + 1.0f) / float(EXTRACTED_RES_R) );
	float2 uv4 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) + 1.0f) / float(EXTRACTED_RES_R) );

	half4 color 	= (half4) ( TFetch2DH(table, SamplerLinearClamp, uv1) * (1.0f-lerp1) + TFetch2DH(table, SamplerLinearClamp, uv2) * lerp1 );
	half4 color2 	= (half4) ( TFetch2DH(table, SamplerLinearClamp, uv3) * (1.0f-lerp1) + TFetch2DH(table, SamplerLinearClamp, uv4) * lerp1 );

	color = (half4) lerp(color, color2, lerp2);

	return color;
}

float4 texture4D_debug(Texture2D table, float r, float mu, float muS, float nu)
{
	const float H 		= absSqrt(Rt * Rt - Rg * Rg);
	const float rho		= absSqrt(r * r - Rg * Rg);
	const float rmu 	= r * mu;
	const float delta 	= rmu * rmu - r * r + Rg * Rg;

	float4 cst 	= (rmu < 0.0 && delta > 0.0) ? float4(1.0, 0.0, 0.0, 0.5 - 0.5 / float(RES_MU)) : float4(-1.0, H * H, H, 0.5 + 0.5 / float(RES_MU));

	float uR 	= 0.5 / float(RES_R) + rho / H * (1.0 - 1.0 / float(RES_R));	
	float uMu 	= cst.w + (rmu * cst.x + sqrt(delta + cst.y)) / (rho + cst.z) * (0.5 - 1.0 / float(RES_MU));
	
	
	
	float uMuS 	= 0.5 / float(RES_MU_S) + (atan(max(muS, -0.1975) * tan(1.26 * 1.1)) / 1.1 + (1.0 - 0.26)) * 0.5 * (1.0 - 1.0 / float(RES_MU_S));
	float lerp1 	= (nu + 1.0) / 2.0 * (float(RES_NU) - 1.0);
	float uNu 	= floor(lerp1);
	lerp1 		= lerp1 - uNu;

	
	

	return float4(float3((uNu+uMuS)/float(RES_NU), uMu, uR), 1.0);
}


float2 getTransmittanceUV(float r, float mu) 
{
    float uR, uMu;
    
	uMu = atan((mu + 0.15) / (1.0 + 0.15) * tan(1.5)) / 1.5;
	uR 	= ( sqrt(max((r - Rg), 0.001) / (Rt - Rg)) ) * ( TRANSMITTANCE_W / EXTRACTED_TRANSMITTANCE_W );	
    
    return float2(uMu, uR);
}





float3 analyticTransmittance(float r, float mu, float d, float3 betaR, float3 betaMEx, float HR, float HM) 
{
   	
  	
  	
  	
 
    return exp(- betaR * opticalDepth(HR, r, mu, d) - betaMEx * opticalDepth(HM, r, mu, d));
}




half3 transmittance(Texture2D transmittanceSampler, float r, float mu) 
{
	float2 uv = getTransmittanceUV(r, mu);
    return TFetch2DH(transmittanceSampler, SamplerLinearClamp, uv).xyz;
}





float3 transmittance(Texture2D transmittanceSampler, float r, float mu, float3 v, float3 x0) 
{
    float3 result;
    float r1 = length(x0);
    float mu1 = dot(x0, v) / r;
    if (mu > 0.0)
	{
        result = min(transmittance(transmittanceSampler, r, mu) / transmittance(transmittanceSampler, r1, mu1), 1.0);
    }
	else
	{
        result = min(transmittance(transmittanceSampler, r1, -mu1) / transmittance(transmittanceSampler, r, -mu), 1.0);
    }
    return result;
}





float3 transmittance(Texture2D transmittanceSampler, float r, float mu, float d) 
{
    float3 result;
    float r1 = sqrt(r * r + d * d + 2.0 * r * mu * d);
    float mu1 = (r * mu + d) / r1;
    
    if (mu > 0.0) 
    {
        result = min(transmittance(transmittanceSampler, r, mu) / transmittance(transmittanceSampler, r1, mu1), 1.0);
    } 
    else 
    {
        result = min(transmittance(transmittanceSampler, r1, -mu1) / transmittance(transmittanceSampler, r, -mu), 1.0);
    }
    return result;
}




half3 transmittanceWithShadow(Texture2D transmittanceSampler, float r, float mu) 
{
    return (mu < -absSqrt(1.0 - (Rg / r) * (Rg / r)))? half3(0.0, 0.0, 0.0) : (half3) transmittance(transmittanceSampler, r, mu);
}


float2 getIrradianceUV(float r, float muS) {
    float uR = (r - Rg) / (Rt - Rg);
    float uMuS = (muS + 0.2) / (1.0 + 0.2);
    return float2(uMuS, uR);

}


float3 irradiance(Texture2D deltaESampler, float r, float muS) 
{
    float2 uv = getIrradianceUV(r, muS);
    return TFetch2D(deltaESampler, SamplerLinearClamp, uv).rgb;
}



float3 getMie(float4 rayMie, float3 betaR) 
{ 
	return rayMie.rgb * rayMie.w / max(rayMie.r, 1e-4) * (betaR.r / betaR);
}


















#define _GAMMA_TRANSFORMATION_H_



half3 GammaCorrection(float3 linearRGB)
{

	float3 mask = step(linearRGB, 0.0031308);
	return (half3)((mask * (linearRGB * 12.92)) + ((1 - mask) * (1.055 * pow(max(linearRGB, 0.00001), (1.0/2.4)) - 0.055)));
}




float3 GammaDecode(float3 inSRGB)
{

	float3 mask = step(inSRGB, 0.03928);
	return (half3)(mask * (inSRGB / 12.92)) + ((1 - mask) * (pow(max((inSRGB + 0.055)/ 1.055, 0.00001), 2.4)));
}




float GammaDecodeF(float f)
{
    float linear_f;
    linear_f = ((f<=0.03928) ? f/12.92 : pow(abs((f + 0.055)/1.055), 2.4));
    return linear_f;
}


























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

	return invLogFarDistance * (half)log2(inViewZ);
}



float DecodeFogCameraZ( float inEncodedZ )
{
	float logFarDistance	= 1.0 / g_psScene.m_fogParam[1].x;

	return exp2( inEncodedZ * logFarDistance );
}



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

	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

half4 GetFurthestVolumetricFog3D( half2 inClipPos, Texture3D inFogVolume )
{
	float3 volCoord = 1.0; 
	volCoord.xy = inClipPos * float2(-0.5,0.5) + float2(0.5,0.5);
	half4 fogColor = (half4)TFetch3D( inFogVolume, SamplerLinearClamp, volCoord.yxz );

	half normalizeFactor = (half)g_psScene.m_fogParam[1].y;
	fogColor.xyz *= normalizeFactor;
	return fogColor;
}

Texture2D g_tex_fog	: TEXUNIT_VOLUMEFOG;




half4 GetVolumetricFog( half2 inClipPos, float inViewZ )
{

	return GetVolumetricFog2D( inClipPos, inViewZ, g_tex_fog );
}



half4 GetFurthestVolumetricFog( half2 inClipPos )
{

	return GetFurthestVolumetricFog2D( inClipPos, g_tex_fog );
}




#define DIRECT_INTENSITY_MULTIPLIER ( 10.0 )	// ç›´æŽ¥å…‰ã®å¼·åº¦ã«ã‹ã‘ã‚‹ã‚¹ã‚±ãƒ¼ãƒ«ã€è¦‹ãŸç›®èª¿æ•´ã®ãŸã‚

#define ENABLE_SUN_CONTRIBUTION
#define ENABLE_MOON_CONTRIBUTION





Texture2D g_CloudyTransmittance	: TEXUNIT5 ;
Texture2D g_CloudyIrradiance 		: TEXUNIT6 ;
Texture2D g_CloudyInscatter 		: TEXUNIT7 ;



















float phaseFunctionM_Approx( const half mu, const half mieK)
{
	return 1.0 / ( 4.0 * M_PI ) * ( 1.0 - mieK * mieK ) / ( ( 1.0 - mieK * mu ) * ( 1.0 - mieK * mu ) );
}




float2 getTransmittanceUV_Approx( const half r, const half mu)
{
	const float uMu	= atan((mu + 0.15) / (1.0 + 0.15) * tan(1.5)) / 1.5;
	const float uR 	= ( sqrt( max( r, 0.001 ) / (Rt - Rg) ) ) * ( TRANSMITTANCE_W / EXTRACTED_TRANSMITTANCE_W );
    return float2(uMu, uR);
}




half3 transmittance_Approx(Texture2D transmittanceSampler, const half r, const half mu)
{
	float2 uv = getTransmittanceUV_Approx( r, mu );
    return TFetch2DH(transmittanceSampler, SamplerLinearClamp, uv).xyz;
}




half3 transmittanceWithShadow_Approx(Texture2D transmittanceSampler, const half r, const half mu)
{
    return ( mu < 0.0 ) ? half3(0.0, 0.0, 0.0) : (half3) transmittance_Approx(transmittanceSampler, r, mu);
}




half3 inscatter(
	Texture2D inscatterSampler,
	const half  y,			
	const half3 v,			
	const half3 s,			
	const half mieK,		
	const float3 betaR,		
	const half sunIntensity,
	const half blend )
{
	const half	r		= Rg + (half)max( y, 0.001 );	
	const half	mu		= v.y;				
    const half	nu 		= (half)dot(v, s);	
    const half	muS		= s.y;				
    const float	phaseR	= phaseFunctionR_Half(nu);
    const float	phaseM	= phaseFunctionM_Approx(nu, mieK);
    half4 _inscatter 	= texture4D_Half(inscatterSampler, r, mu, muS, nu) * ( 1.0 - blend ) + texture4D_Half(g_CloudyInscatter, r, mu, muS, nu) * blend;
    _inscatter = (half4)max(_inscatter, 0.0);

    half3 result = (half3)max(_inscatter.xyz * phaseR + getMie(_inscatter, betaR) * phaseM, 0.0);
    return result * sunIntensity;
}




half4 sunColor(
	Texture2D transmittanceSampler,
	const half  y,	
	const half3 v,	
	const half3 s,	
	const half sunIntensity,
	const half blend )
{
	const half	r	= Rg + (half)max( y, 0.001 );	
	const half	mu	= v.y; 
    half3 transmit = transmittanceWithShadow_Approx(transmittanceSampler, r, mu) * ( 1.0 - blend ) + transmittanceWithShadow_Approx(g_CloudyTransmittance, r, mu) * blend;

	
    
    half isun = (half)step(cos(M_PI / 180.0), dot(v, s)) * sunIntensity; 

	return ( mu < 0.0) ? half4(0, 0, 0, 0) : half4(transmit * isun, isun); 
}















































































half4 Unpack4Float32(float p)
{
	return (half4)frac( p / float4( 64.0, 4096.0, 262144.0, 16777216.0 ) );
}



half2 Unpack2Float32(float p)
{
	return (half2)frac( p / float2( 4096.0, 16777216.0 ) );
}



half CalcInfluenceOfFog( half elevationAngle, half influenceOfFogFix, half influenceOfFogVar, half falloff, half invFalloffStart )
{
	float	t = saturate( elevationAngle * invFalloffStart );
	half	influenceOfFog = influenceOfFogFix + influenceOfFogVar * (half)( ( falloff * t + t ) / ( falloff * t + 1 ) );
	return influenceOfFog;
}










#define EXPAND_HORIZONTAL_LINE

#define	FIXED_R		( 6360.01 ) 	// = Rg + 10m / åœ°çƒä¸­å¿ƒã¨è¦³æ¸¬è€…ã®è·é›¢. TPPã§ã¯æç”»è² è·è»½æ¸›ã®ãŸã‚å›ºå®šåŒ–ã™ã‚‹ã€‚
#define FIXED_R2	( 40449727.2001 )	// Rg * Rg





float BoundedExposure( float exposure, half minEv, half maxEv, half minScale, half maxScale )
{
	half currEv = (half)log2( exposure );
	half t = (half)saturate( ( currEv - minEv ) / ( maxEv - minEv ) );
	half ratio = minScale + t * ( maxScale - minScale );
	return exposure * ratio;
}







half4 texture4D_Half_fixed_eyepos(Texture2D table, const half mu, const half muS, const half nu)
{
	
	const float H 		= absSqrt(Rt * Rt - Rg * Rg);
	const float rho 	= absSqrt(FIXED_R2 - Rg * Rg);
	const float rmu 	= FIXED_R * mu;
	const float delta 	= rmu * rmu - FIXED_R2 + Rg * Rg;

	float4 cst 	= ((rmu<0.0f)&&(delta>0.0f)) ? float4(1.0f, 0.0f, 0.0f, 0.5f - 0.5f / float(RES_MU)) : float4(-1.0f, H * H, H, 0.5f + 0.5f / float(RES_MU));
	float uMu 	= cst.w + (cst.x * rmu + sqrt(delta + cst.y)) / (rho + cst.z) * (0.5f - 1.0f / float(RES_MU));

	
	
	
	float uMuS 	= 0.5f / float(RES_MU_S) + (atan(max(muS, -0.1975f) * tan(1.26f * 1.1f)) / 1.1f + (1.0f - 0.26f)) * 0.5f * (1.0f - 1.0f / float(RES_MU_S));

	float lerp1 	= (nu + 1.0f) / 2.0f * (float(RES_NU) - 1.0f);
	float uNu 	= floor(lerp1);
	lerp1 		= lerp1 - uNu;


	float uR 	= 0.5f / float(RES_R) + rho / H * (1.0f - 1.0f / float(RES_R)); 
	uR		= saturate( uR * ( RES_R / EXTRACTED_RES_R ) ); 
	
	float lerp2 = uR*(EXTRACTED_RES_R-1.0f);
	lerp2 		= lerp2 - floor(uR*(EXTRACTED_RES_R-1.0f));
	float2 uv1 = float2( (uNu + uMuS)		/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) ) / float(EXTRACTED_RES_R) );
	float2 uv2 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) ) / float(EXTRACTED_RES_R) );
	float2 uv3 = float2( (uNu + uMuS) 		/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) + 1.0f) / float(EXTRACTED_RES_R) );
	float2 uv4 = float2( (uNu + uMuS + 1.0f)/ float(RES_NU), (uMu + floor(uR*(float(EXTRACTED_RES_R)-1.0f)) + 1.0f) / float(EXTRACTED_RES_R) );
	half4 color 	= (half4) ( TFetch2DH(table, SamplerLinearClamp, uv1) * (1.0f-lerp1) + TFetch2DH(table, SamplerLinearClamp, uv2) * lerp1 );
	half4 color2 	= (half4) ( TFetch2DH(table, SamplerLinearClamp, uv3) * (1.0f-lerp1) + TFetch2DH(table, SamplerLinearClamp, uv4) * lerp1 );
	color = (half4) lerp(color, color2, lerp2);
	return color;
}




half3 inscatterApprox(
	Texture2D inscatterSampler,
	const half3 v,			
	const half3 s,			
	const half	nu,			
	const half mieK,		
	const float3 betaR,		
	const half sunIntensity,
	const half blend )
{
	const half	mu		= v.y;				
    const half	muS		= s.y;				
    const float	phaseR	= phaseFunctionR_Half(nu);
    const float	phaseM	= phaseFunctionM_Approx(nu, mieK);
    half4 inscatterColor= texture4D_Half_fixed_eyepos(inscatterSampler, mu, muS, nu);
    inscatterColor = (half4)max(inscatterColor, 0.0);

	
	const float3 mie		= getMie(inscatterColor,betaR);
	const float3 rayleigh	= inscatterColor.xyz;
	const float3 cloudy		= 0.1 * ( length(inscatterColor.xyz) * 0.8 + mie * phaseM * 0.2 );
	half3 result = (half3)max( rayleigh * phaseR * ( 1.0 - blend ) + cloudy * blend + mie * phaseM, 0.0);

    return result * sunIntensity;
}































































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




inline float4 TransformPosition( VSScene scene, VSObject object,
								 float4 position, out float4 hPosition )
{

	float4	onCameraRelative ;
	float3	worldPosition ;
	
	
	
	onCameraRelative = ApplyMatrixT( object.m_viewWorld, position );
	hPosition.xyzw = ApplyMatrixT( scene.m_projection, onCameraRelative.xyzw );
	worldPosition.xyz = ApplyMatrixT( object.m_world, position ).xyz ;
	return float4( worldPosition, 1.0 ) ;
}




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




#define MODEL_FORWARD_H_












float GetCurrentExposureValue() { 
	return g_psScene.m_exposure.z;
}




half3 GetSunLightDirection(){
	return (half3)g_psObject.m_localParam[0].xyz;
}




half3 GetSunLightColor(){

	return (half3)g_psObject.m_localParam[1].xyz;
}




half3 GetExposureAdjustedSunLightColor(){
	return (half3)(g_psObject.m_localParam[1].xyz * GetCurrentExposureValue());
}




float GetSunLightInverseShadowFadeRange(){
	return g_psLight.m_lightParams[8].x;
}




float GetSunLightNegativeShadowFadeRatio(){
	return g_psLight.m_lightParams[8].y;
}




float GetSunLightShadowIntervalBaseLog(){
	return g_psLight.m_lightParams[8].z;
}




float GetSunLightShadowOffset(){
	return g_psLight.m_lightParams[8].w;
}




float GetSunLightShadowFadeStartDistance(){
	return g_psObject.m_localParam[0].w;
}




float GetSunLightShadowInvFadeRange(){
	return g_psObject.m_localParam[1].w;
}





float3 GetFirstApproximatedLightPosition(){
	return g_psLight.m_lightParams[2].xyz;
}




float3 GetFirstApproximatedLightColor(){

	return g_psLight.m_lightParams[3].xyz;
}




float GetFirstApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[2].w;
}




float GetFirstApproximatedLightDimmer(){
	return g_psLight.m_lightParams[3].w;
}




float GetFirstApproximatedLightInnerRange(){
	return g_psObject.m_localParam[2].x;
}




float3 GetSecondApproximatedLightPosition(){
	return g_psLight.m_lightParams[4].xyz;
}




float3 GetSecondApproximatedLightColor(){

	return g_psLight.m_lightParams[5].xyz;
}




float GetSecondApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[4].w;
}




float GetSecondApproximatedLightDimmer(){
	return g_psLight.m_lightParams[5].w;
}




float GetSecondApproximatedLightInnerRange(){
	return g_psObject.m_localParam[2].y;
}




float3 GetThirdApproximatedLightPosition(){
	return g_psLight.m_lightParams[6].xyz;
}




float3 GetThirdApproximatedLightColor(){

	return g_psLight.m_lightParams[7].xyz;
}




float GetThirdApproximatedLightAttenuationParameter(){
	return g_psLight.m_lightParams[6].w;
}




float GetThirdApproximatedLightDimmer(){
	return g_psLight.m_lightParams[7].w;
}




float GetThirdApproximatedLightInnerRange(){
	return g_psObject.m_localParam[2].z;
}




float3 GetHemisphereAmbientLightFactor0() {
	return g_psLight.m_lightParams[0].xyz;
}





float3 GetHemisphereAmbientLightFactor1() {
	return g_psLight.m_lightParams[1].xyz;
}







float GetShadowNearRange()
{

	return g_psScene.m_shadowProjection2[3].y;
}



float GetShadowInvBlockUnitRange()
{

	return g_psScene.m_shadowProjection2[3].z;
}




float GetShadowBias()
{

	return g_psScene.m_shadowProjection2[3].w;
}




TMatrix4x4 GetShadowProjectionMatrix()
{

	return g_psScene.m_shadowProjection;
}




TMatrix4x4 GetShadowProjectionMatrix2()
{

	return g_psScene.m_shadowProjection2;
}







half3 CalculateHemisphereAmbinetLight( half3 inNormal ) {
	half3 c0 = (half3)GetHemisphereAmbientLightFactor0() ;
	half3 c1 = (half3)GetHemisphereAmbientLightFactor1() ; 
    
	half fT = (half)dot(inNormal, half3(0, 1, 0));
        
	return ( c0 * fT + c1 ) ;
}






#define SUPPRESS_BY_HAND


#define DOME_REPEATS		2.0h
#define DOME2_REPEATS		3.0h
#define DOME3_REPEATS		2.0h
#define CYL_REPEATS			2.0h



float hash( float n )
{
    return frac(sin(n)*43758.5453);
}



float simplexNoise( float2 x )
{
	const float r = 113.0; 
	float2 p = floor(x);
	float2 f = frac(x);
	f = f * f * ( 3.0 - 2.0 * f );
	float n = p.x + r * p.y;
	return	lerp(
				lerp( hash(n+0.0), hash(n+1.0), f.x ),
				lerp( hash(n+r), hash(n+r+1.0), f.x ),
				f.y
			);
}























































half4 Opaqueblend( half4 src, half4 dst )
{
	half3	c = src.xyz * src.w + dst.xyz * ( 1.0h - src.w );
	half	a = (half)max( src.w, dst.w );
	return half4( c.xyz, a );
}



















































inline void NScreenToClipCoordinate( float2 inPixelPosition, out float2 outClipPosition)
{

	outClipPosition = inPixelPosition / g_psSystem.m_renderInfo.xy ;
	outClipPosition = outClipPosition * float2( 2.0, -2.0 ) + float2( -1.0, 1.0 ) ;
}



inline void NPremultipliedAlpha( half3 inColor, half inAlpha, out half4 outColor)
{

  outColor = half4((inColor*inAlpha), inAlpha);
}



inline void NInCloudScatteringColor( half3 inViewDir, half inGain, out half3 outColor)
{

	half3	lightDir= (half3)g_psMaterial.m_materials[0].xyz;
    half	nu		= (half)dot( inViewDir, lightDir ); 
	half	mieK	= (half)g_psMaterial.m_materials[2].w; 
	float	phaseM	= phaseFunctionM_Approx( nu, mieK );
	outColor = GetExposureAdjustedSunLightColor();
	outColor *= 0.5 * inGain * (half)( phaseM + phaseM * phaseM ); 
}



inline void NCylScatteringColor( half3 inViewDir, half inGain, out half3 outColor)
{

	half3	lightDir= (half3)g_psMaterial.m_materials[0].xyz;
    half	nu		= (half)dot( inViewDir, lightDir ); 
	half	mieK	= (half)g_psMaterial.m_materials[3].w; 
	float	phaseM	= phaseFunctionM_Approx( nu, mieK );
	outColor = GetExposureAdjustedSunLightColor();
	outColor *= inGain * (half)phaseM;
}



inline void NCloudColor( half3 inViewDir, half3 inAmbLight, half3 inCloudInscatter, float2 inCloudUV, half inCloudAlpha, Texture2D inCloudTexture, SamplerState inCloudSampler, out half4 outInfo)
{

	float2	uv	= inCloudUV.xy + float2( 0, g_psMaterial.m_materials[1].y );
	const half		repeats		= DOME_REPEATS;
	const half3		texColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * uv ).xyz;

	
	half	density		= (half)g_psMaterial.m_materials[1].z;
	half	optDepth	= 0.4 * (half)dot( half3(1,1,1), texColor.xyz );

	
	float	densityScroll	= g_psMaterial.m_materials[1].x;
	half	densityPower	= (half)g_psMaterial.m_materials[5].x;
	half4	subTexColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * ( inCloudUV.xy + float2( 0, densityScroll ) ) );
	half p = subTexColor.w;
	optDepth *= (half)pow( abs(optDepth), densityPower * p );

	optDepth *= 3.0h;
	outInfo.xyz	= inCloudInscatter + inAmbLight;
	outInfo.w	= density * optDepth * inCloudAlpha;
}



inline void NDom2CloudColor( half3 inViewDir, half3 inAmbLight, half3 inCloudInscatter, float2 inCloudUV, half inCloudAlpha, Texture2D inCloudTexture, SamplerState inCloudSampler, out half4 outInfo)
{

	float2	uv	= inCloudUV.xy + float2( 0, g_psMaterial.m_materials[4].y );
	const half		repeats		= DOME2_REPEATS;
	const half3		texColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * uv ).xyz;

	
	half	density		= (half)g_psMaterial.m_materials[2].y;
	half	optDepth	= 0.33333h * (half)dot( half3(1,1,1), texColor.xyz );

	
	float	densityScroll	= g_psMaterial.m_materials[2].z;
	half	densityPower	= (half)g_psMaterial.m_materials[3].x;
	half4	subTexColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * ( inCloudUV.xy + float2( 0, densityScroll ) ) );
	half p = subTexColor.w;
	optDepth *= (half)pow( abs(optDepth), densityPower * p );
	optDepth *= 3.0h;
	
	outInfo.xyz	= inCloudInscatter + inAmbLight;
	outInfo.w	= density * optDepth * inCloudAlpha;
}



inline void NDom3CloudColor( half3 inViewDir, half3 inAmbLight, half3 inCloudInscatter, float2 inCloudUV, half inCloudAlpha, Texture2D inCloudTexture, SamplerState inCloudSampler, out half4 outInfo)
{

	float2	uv	= inCloudUV.xy + float2( 0, g_psMaterial.m_materials[0].w );
	const half		repeats		= DOME3_REPEATS;
	const half3		texColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * uv ).xyz;

	
	half	density		= (half)g_psMaterial.m_materials[5].z;
	half	optDepth	= 0.4 * (half)dot( half3(1,1,1), texColor.xyz );

	
	float	densityScroll	= g_psMaterial.m_materials[3].z;
	half	densityPower	= (half)g_psMaterial.m_materials[4].z;
	half4	subTexColor	= TFetch2DH( inCloudTexture, inCloudSampler, repeats * ( inCloudUV.xy + float2( 0, densityScroll ) ) );
	half p = subTexColor.w;
	optDepth *= (half)pow( abs(optDepth), densityPower * p );
	optDepth *= 3.0h;
	
	outInfo.xyz	= inCloudInscatter + inAmbLight;
	outInfo.w	= density * optDepth * inCloudAlpha;
}



inline void NCylCloudColor( half3 inViewDir, half3 inAmbLight, half3 inCloudInscatter, float2 inCloudUV, half inCloudAlpha, Texture2D inCloudTexture, SamplerState inCloudSampler, out half4 outInfo)
{

	
	const half		repeats		= CYL_REPEATS;
	const float2	uv			= inCloudUV.xy + float2( 0.0, g_psMaterial.m_materials[5].y );
	half4			texColor	= TFetch2DH( inCloudTexture, inCloudSampler, float2( uv.y * repeats, uv.x ) );

	half density  = (half)g_psMaterial.m_materials[4].x;
	half optDepth = texColor.w; 

	
	float	densityScroll	= g_psMaterial.m_materials[7].y;
	half	densityPower	= (half)g_psMaterial.m_materials[7].z;
	half4	subTexColor	= TFetch2DH( inCloudTexture, inCloudSampler, float2( repeats * ( densityScroll + inCloudUV.y ), inCloudUV.x ) );
	optDepth *= optDepth < 1e-4h ? 0.0h : (half)pow( abs(optDepth), densityPower * subTexColor.g );

	outInfo.xyz	= inAmbLight + inCloudInscatter;
	outInfo.w	= density * optDepth * inCloudAlpha;
}



inline void NLighting( half inColorScale, half inLightExtinction, half4 inCloudInfo0, half4 inCloudInfo1, half4 inCloudInfo2, half4 inCloudInfo3, out half4 outColor)
{


	
	float	opticalDepth= inCloudInfo0.w + inCloudInfo1.w + inCloudInfo2.w + 1e-4h;
	half	domeExtinction = 1.0h - (half)exp( - opticalDepth );
	half4	domeColor = half4(
				/*domeExtinction * */( ( inCloudInfo0.xyz * inCloudInfo0.w + inCloudInfo1.xyz * inCloudInfo1.w + inCloudInfo2.xyz * inCloudInfo2.w ) / opticalDepth ),
				domeExtinction
			);

	
	half	cylExtinction = 1.5h - (half)exp( -inCloudInfo3.w );
	half4	cylColor = half4( inCloudInfo3.xyz /* * cylExtinction */, cylExtinction );

	
	half4	color = Opaqueblend( cylColor, domeColor );

	
	half lt = inLightExtinction;
	outColor.xyz	= color.xyz * inColorScale;
	outColor.xyz	*= lt + ( 2.0h - lt ) * ( 1.0h - color.w );
	outColor.w		= color.w;
#ifdef SUPPRESS_BY_HAND
	outColor *= color.w * color.w;
#endif
}



inline void NCalcurateOutputColor( half4 inColor, out half4 outColor)
{

	outColor = inColor;
	outColor.xyz = GammaCorrection(outColor.xyz);
}



inline void NViewRay2( float3 inWorldPos, out half4 outViewRay)
{

	
	const half	altitude = FIXED_R - Rg; 
	float3	worldPos	= inWorldPos;
	float3	eyePos		= 0.001 * GetEyePosition();	
	half3	viewDir		= (half3)normalize( worldPos - eyePos );
	outViewRay.xyz = viewDir;
#ifdef EXPAND_HORIZONTAL_LINE
	outViewRay.y = (half)max( outViewRay.y , 0.0f );
#endif
	outViewRay.w = (half)eyePos.y + altitude;
}



inline void NApplyFurthestFog2( half inViewZenith, half4 inColor, half2 inClipCoord, out half4 outColor)
{

	half4	fogColor = GetFurthestVolumetricFog( inClipCoord );

	
	half	influenceOfFogFix	= (half)g_psMaterial.m_materials[7].x;
	half	influenceOfFogVar	= (half)g_psMaterial.m_materials[5].w;
	half	falloff				= (half)g_psMaterial.m_materials[6].x;
	half	invFalloffStart		= (half)g_psMaterial.m_materials[6].y;
	half influenceOfFog = CalcInfluenceOfFog( ( inViewZenith - 1.0h ), influenceOfFogFix, influenceOfFogVar, falloff, invFalloffStart );

	
	fogColor.xyz *= influenceOfFog;
	fogColor.w = 1 - ( 1 - fogColor.w ) * influenceOfFog;
	outColor = half4( inColor.xyz * fogColor.w + fogColor.xyz, inColor.a );
}



inline void NDitheringTppSky( float2 inVPos, half4 inColor, Texture2D inMesh, out half4 outColor)
{

	const float MESH_SIZE = (8.0);
	half2 uv = (half2) frac(inVPos * float2(1.0/MESH_SIZE, 1.0/MESH_SIZE));
	outColor = inColor + ( TFetch2DH(inMesh, SamplerPoint, uv).x - 0.8h ) / 64.0h;
	outColor = (half4)max( outColor, 0 );
}











Texture2D	NDitheringTppSky_dither_inMesh;
SamplerState	NCloudColor_cloudColor_inCloudSampler;
Texture2D	NCloudColor_cloudColor_inCloudTexture;
SamplerState	NDom2CloudColor_dom2CloudColor_inCloudSampler;
Texture2D	NDom2CloudColor_dom2CloudColor_inCloudTexture;
SamplerState	NDom3CloudColor_dom3CloudColor_inCloudSampler;
Texture2D	NDom3CloudColor_dom3CloudColor_inCloudTexture;
SamplerState	NCylCloudColor_cylCloudColor_inCloudSampler;
Texture2D	NCylCloudColor_cylCloudColor_inCloudTexture;
Texture2D	inCloudTexture	:TEXUNIT0 ;
Texture2D	inCylCloudTexture	:TEXUNIT1 ;
Texture2D	inMesh	:TEXUNIT15 ;
SamplerState	inCloudSampler	:SAMPLERUNIT0 ;
SamplerState	inCylCloudSampler	:SAMPLERUNIT1 ;
void ps_main(

	 in	half4	inColor	: COLOR0,
	 in	float4	inUV	: TEXCOORD0,
	 in	float4	inWorldPos	: TEXCOORD1,
	 in	float4	inDomLightParam	: TEXCOORD2,
	 in	float4	inCylLightParam	: TEXCOORD3,
	 in	float2	inLightParam3	: TEXCOORD5,
	 in	float4	inVPos	: VPOS,
	 out	half4	outColor	: OUT_COLOR0
)
{
	inVPos = ToVPos4( inVPos ) ;
	float2	NScreenToClipCoordinate_screenToClipcoord_inPixelPosition ;
	float2 NScreenToClipCoordinate_screenToClipcoord_outClipPosition ;
	NScreenToClipCoordinate_screenToClipcoord_inPixelPosition = inVPos.xy ;
	NScreenToClipCoordinate( NScreenToClipCoordinate_screenToClipcoord_inPixelPosition, NScreenToClipCoordinate_screenToClipcoord_outClipPosition ) ;


	float3	NViewRay2_viewRay_inWorldPos ;
	half4 NViewRay2_viewRay_outViewRay ;
	NViewRay2_viewRay_inWorldPos = inWorldPos.xyz ;
	NViewRay2( NViewRay2_viewRay_inWorldPos, NViewRay2_viewRay_outViewRay ) ;


	half3	NCylScatteringColor_cylCloudInscatter_inViewDir ;
	half	NCylScatteringColor_cylCloudInscatter_inGain ;
	half3 NCylScatteringColor_cylCloudInscatter_outColor ;
	NCylScatteringColor_cylCloudInscatter_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NCylScatteringColor_cylCloudInscatter_inGain = (half)inCylLightParam.w ;
	NCylScatteringColor( NCylScatteringColor_cylCloudInscatter_inViewDir, NCylScatteringColor_cylCloudInscatter_inGain, NCylScatteringColor_cylCloudInscatter_outColor ) ;


	half3	NCylCloudColor_cylCloudColor_inViewDir ;
	half3	NCylCloudColor_cylCloudColor_inAmbLight ;
	half3	NCylCloudColor_cylCloudColor_inCloudInscatter ;
	float2	NCylCloudColor_cylCloudColor_inCloudUV ;
	half	NCylCloudColor_cylCloudColor_inCloudAlpha ;
			half4 NCylCloudColor_cylCloudColor_outInfo ;
	NCylCloudColor_cylCloudColor_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NCylCloudColor_cylCloudColor_inAmbLight = (half3)inCylLightParam.xyz ;
	NCylCloudColor_cylCloudColor_inCloudInscatter = NCylScatteringColor_cylCloudInscatter_outColor ;
	NCylCloudColor_cylCloudColor_inCloudUV = inUV.zw ;
	NCylCloudColor_cylCloudColor_inCloudAlpha = inColor.y ;
	NCylCloudColor( NCylCloudColor_cylCloudColor_inViewDir, NCylCloudColor_cylCloudColor_inAmbLight, NCylCloudColor_cylCloudColor_inCloudInscatter, NCylCloudColor_cylCloudColor_inCloudUV, NCylCloudColor_cylCloudColor_inCloudAlpha, inCylCloudTexture, inCylCloudSampler, NCylCloudColor_cylCloudColor_outInfo ) ;


	half3	NInCloudScatteringColor_cloudInscatter_inViewDir ;
	half	NInCloudScatteringColor_cloudInscatter_inGain ;
	half3 NInCloudScatteringColor_cloudInscatter_outColor ;
	NInCloudScatteringColor_cloudInscatter_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NInCloudScatteringColor_cloudInscatter_inGain = (half)inDomLightParam.w ;
	NInCloudScatteringColor( NInCloudScatteringColor_cloudInscatter_inViewDir, NInCloudScatteringColor_cloudInscatter_inGain, NInCloudScatteringColor_cloudInscatter_outColor ) ;


	half3	NDom3CloudColor_dom3CloudColor_inViewDir ;
	half3	NDom3CloudColor_dom3CloudColor_inAmbLight ;
	half3	NDom3CloudColor_dom3CloudColor_inCloudInscatter ;
	float2	NDom3CloudColor_dom3CloudColor_inCloudUV ;
	half	NDom3CloudColor_dom3CloudColor_inCloudAlpha ;
			half4 NDom3CloudColor_dom3CloudColor_outInfo ;
	NDom3CloudColor_dom3CloudColor_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NDom3CloudColor_dom3CloudColor_inAmbLight = (half3)inDomLightParam.xyz ;
	NDom3CloudColor_dom3CloudColor_inCloudInscatter = NInCloudScatteringColor_cloudInscatter_outColor ;
	NDom3CloudColor_dom3CloudColor_inCloudUV = inUV.xy ;
	NDom3CloudColor_dom3CloudColor_inCloudAlpha = inColor.w ;
	NDom3CloudColor( NDom3CloudColor_dom3CloudColor_inViewDir, NDom3CloudColor_dom3CloudColor_inAmbLight, NDom3CloudColor_dom3CloudColor_inCloudInscatter, NDom3CloudColor_dom3CloudColor_inCloudUV, NDom3CloudColor_dom3CloudColor_inCloudAlpha, inCloudTexture, inCloudSampler, NDom3CloudColor_dom3CloudColor_outInfo ) ;


	half3	NDom2CloudColor_dom2CloudColor_inViewDir ;
	half3	NDom2CloudColor_dom2CloudColor_inAmbLight ;
	half3	NDom2CloudColor_dom2CloudColor_inCloudInscatter ;
	float2	NDom2CloudColor_dom2CloudColor_inCloudUV ;
	half	NDom2CloudColor_dom2CloudColor_inCloudAlpha ;
			half4 NDom2CloudColor_dom2CloudColor_outInfo ;
	NDom2CloudColor_dom2CloudColor_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NDom2CloudColor_dom2CloudColor_inAmbLight = (half3)inDomLightParam.xyz ;
	NDom2CloudColor_dom2CloudColor_inCloudInscatter = NInCloudScatteringColor_cloudInscatter_outColor ;
	NDom2CloudColor_dom2CloudColor_inCloudUV = inUV.xy ;
	NDom2CloudColor_dom2CloudColor_inCloudAlpha = inColor.z ;
	NDom2CloudColor( NDom2CloudColor_dom2CloudColor_inViewDir, NDom2CloudColor_dom2CloudColor_inAmbLight, NDom2CloudColor_dom2CloudColor_inCloudInscatter, NDom2CloudColor_dom2CloudColor_inCloudUV, NDom2CloudColor_dom2CloudColor_inCloudAlpha, inCloudTexture, inCloudSampler, NDom2CloudColor_dom2CloudColor_outInfo ) ;


	half3	NCloudColor_cloudColor_inViewDir ;
	half3	NCloudColor_cloudColor_inAmbLight ;
	half3	NCloudColor_cloudColor_inCloudInscatter ;
	float2	NCloudColor_cloudColor_inCloudUV ;
	half	NCloudColor_cloudColor_inCloudAlpha ;
			half4 NCloudColor_cloudColor_outInfo ;
	NCloudColor_cloudColor_inViewDir = NViewRay2_viewRay_outViewRay.xyz ;
	NCloudColor_cloudColor_inAmbLight = (half3)inDomLightParam.xyz ;
	NCloudColor_cloudColor_inCloudInscatter = NInCloudScatteringColor_cloudInscatter_outColor ;
	NCloudColor_cloudColor_inCloudUV = inUV.xy ;
	NCloudColor_cloudColor_inCloudAlpha = inColor.x ;
	NCloudColor( NCloudColor_cloudColor_inViewDir, NCloudColor_cloudColor_inAmbLight, NCloudColor_cloudColor_inCloudInscatter, NCloudColor_cloudColor_inCloudUV, NCloudColor_cloudColor_inCloudAlpha, inCloudTexture, inCloudSampler, NCloudColor_cloudColor_outInfo ) ;


	half	NLighting_lighting_inColorScale ;
	half	NLighting_lighting_inLightExtinction ;
	half4	NLighting_lighting_inCloudInfo0 ;
	half4	NLighting_lighting_inCloudInfo1 ;
	half4	NLighting_lighting_inCloudInfo2 ;
	half4	NLighting_lighting_inCloudInfo3 ;
	half4 NLighting_lighting_outColor ;
	NLighting_lighting_inColorScale = (half)inLightParam3.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                x ;
	NLighting_lighting_inLightExtinction = (half)inLightParam3.y ;
	NLighting_lighting_inCloudInfo0 = NCloudColor_cloudColor_outInfo ;
	NLighting_lighting_inCloudInfo1 = NDom2CloudColor_dom2CloudColor_outInfo ;
	NLighting_lighting_inCloudInfo2 = NDom3CloudColor_dom3CloudColor_outInfo ;
	NLighting_lighting_inCloudInfo3 = NCylCloudColor_cylCloudColor_outInfo ;
	NLighting( NLighting_lighting_inColorScale, NLighting_lighting_inLightExtinction, NLighting_lighting_inCloudInfo0, NLighting_lighting_inCloudInfo1, NLighting_lighting_inCloudInfo2, NLighting_lighting_inCloudInfo3, NLighting_lighting_outColor ) ;


	half	NApplyFurthestFog2_applyFog_inViewZenith ;
	half4	NApplyFurthestFog2_applyFog_inColor ;
	half2	NApplyFurthestFog2_applyFog_inClipCoord ;
	half4 NApplyFurthestFog2_applyFog_outColor ;
	NApplyFurthestFog2_applyFog_inViewZenith = NViewRay2_viewRay_outViewRay.y ;
	NApplyFurthestFog2_applyFog_inColor = NLighting_lighting_outColor ;
	NApplyFurthestFog2_applyFog_inClipCoord = (half2)NScreenToClipCoordinate_screenToClipcoord_outClipPosition ;
	NApplyFurthestFog2( NApplyFurthestFog2_applyFog_inViewZenith, NApplyFurthestFog2_applyFog_inColor, NApplyFurthestFog2_applyFog_inClipCoord, NApplyFurthestFog2_applyFog_outColor ) ;


	float2	NDitheringTppSky_dither_inVPos ;
	half4	NDitheringTppSky_dither_inColor ;
		half4 NDitheringTppSky_dither_outColor ;
	NDitheringTppSky_dither_inVPos = inVPos.xy ;
	NDitheringTppSky_dither_inColor = NApplyFurthestFog2_applyFog_outColor ;
	NDitheringTppSky( NDitheringTppSky_dither_inVPos, NDitheringTppSky_dither_inColor, inMesh, NDitheringTppSky_dither_outColor ) ;


	half4	NCalcurateOutputColor_calcOutputColor_inColor ;
	half4 NCalcurateOutputColor_calcOutputColor_outColor ;
	NCalcurateOutputColor_calcOutputColor_inColor = NDitheringTppSky_dither_outColor ;
	NCalcurateOutputColor( NCalcurateOutputColor_calcOutputColor_inColor, NCalcurateOutputColor_calcOutputColor_outColor ) ;


	half3	NPremultipliedAlpha_premultipliedAlpha_inColor ;
	half	NPremultipliedAlpha_premultipliedAlpha_inAlpha ;
	half4 NPremultipliedAlpha_premultipliedAlpha_outColor ;
	NPremultipliedAlpha_premultipliedAlpha_inColor = NCalcurateOutputColor_calcOutputColor_outColor.xyz ;
	NPremultipliedAlpha_premultipliedAlpha_inAlpha = NCalcurateOutputColor_calcOutputColor_outColor.w ;
	NPremultipliedAlpha( NPremultipliedAlpha_premultipliedAlpha_inColor, NPremultipliedAlpha_premultipliedAlpha_inAlpha, NPremultipliedAlpha_premultipliedAlpha_outColor ) ;


	outColor = NPremultipliedAlpha_premultipliedAlpha_outColor ;




}
