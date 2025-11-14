/**
 * @file	Gr\Dg\DgShaderDefineForDx11Gen.h
 * @ingroup	DgShader
 *
 * @brief	Declares the dg shader define for dx 11 generate class.
**/

#ifndef _DG_SHADER_DEF_FOR_DIRECTX11_GEN_H_
#define _DG_SHADER_DEF_FOR_DIRECTX11_GEN_H_


// ----------------------------------------------------------------
// ï¿½Vï¿½Fï¿½[ï¿½_ï¿½[ï¿½èï¿½oï¿½bï¿½tï¿½@ï¿½ï¿½ï¿½`
#define SHADER_CONSTANTBUFFER_SYSTEM		0
#define SHADER_CONSTANTBUFFER_RENDERBUFFER	1
#define SHADER_CONSTANTBUFFER_SCENE			2
#define SHADER_CONSTANTBUFFER_LIGHTS		3
#define SHADER_CONSTANTBUFFER_MATERIAL		4
#define SHADER_CONSTANTBUFFER_OBJECT		5
#define SHADER_CONSTANTBUFFER_BONES			6
#define SHADER_CONSTANTBUFFER_WORK			7

// legacy
#define SHADER_CONSTANTBUFFER_LIGHT			SHADER_CONSTANTBUFFER_LIGHTS

// --------------------------------
// ï¿½Vï¿½Xï¿½eï¿½ï¿½ï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
struct SSystem
{
	float4		m_param;					///< wï¿½ÉAï¿½ï¿½ï¿½tï¿½@ï¿½eï¿½Xï¿½gï¿½ï¿½èlï¿½ï¿½ï¿½ï¿½ï¿½Ägï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Óï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ÌÅcï¿½ï¿½ï¿½Äï¿½ï¿½ï¿½ï¿½Üï¿½
	float4		m_renderInfo;				///< ï¿½ï¿½ï¿½ÝÌrï¿½ï¿½ï¿½[ï¿½|ï¿½[ï¿½gï¿½Tï¿½Cï¿½Yï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½iVPOS/WPOSï¿½Ïï¿½ï¿½Ìï¿½ï¿½ßj
	float4		m_renderBuffer ;			///< (xy:ï¿½ï¿½ï¿½Ýï¿½ï¿½ï¿½ï¿½_ï¿½ï¿½ï¿½ï¿½ï¿½Oï¿½ï¿½ï¿½oï¿½bï¿½tï¿½@ï¿½ÌTï¿½Cï¿½Y,zw:ï¿½Tï¿½Cï¿½Yï¿½Ìtï¿½ï¿½)
	float4		m_dominantLightDir;			///< ï¿½xï¿½zï¿½Iï¿½Èï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½iViewspeceï¿½j
};
typedef SSystem VSSystem;
typedef SSystem PSSystem;

#define SHADER_CONST_SYSTEM_PARAM				0
#define SHADER_CONST_SYSTEM_RENDERINFO			1
#define SHADER_CONST_SYSTEM_RENDERBUFFER		2
#define SHADER_CONST_SYSTEM_DOMINANT_LIGHT_DIR	3
#define SHADER_CONSTANTBUFFER_SYSTEM_SIZE		4


// --------------------------------
// ï¿½Vï¿½[ï¿½ï¿½ï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^ï¿½è
struct SScene
{
	TMatrix4x4		m_projectionView;		///< ( ï¿½ï¿½ï¿½e x ï¿½rï¿½ï¿½ï¿½[ )ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_projection;			///< ï¿½ï¿½ï¿½eï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_view;					///< ï¿½rï¿½ï¿½ï¿½[ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_shadowProjection;		///< ï¿½eï¿½ï¿½ï¿½eï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_shadowProjection2;	///< ï¿½eï¿½ï¿½ï¿½eï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X2
	float4			m_eyepos;				///< ï¿½ï¿½ï¿½_ï¿½ï¿½ï¿½W
	float4			m_projectionParam;		///< ï¿½ï¿½ï¿½eï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^( Z => W ï¿½Ïï¿½ï¿½ï¿½ï¿½p )
	float4			m_viewportSize;			///< ï¿½rï¿½ï¿½ï¿½[ï¿½|ï¿½[ï¿½gï¿½Tï¿½Cï¿½Y
	float4			m_exposure;				///< ï¿½Iï¿½oï¿½ÖAï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
	float4			m_fogParam[3];			///< ï¿½tï¿½Hï¿½Oï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
	float4			m_fogColor;				///< ï¿½tï¿½Hï¿½Oï¿½Jï¿½ï¿½ï¿½[
	float4			m_cameraCenterOffset;	///< ï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½hï¿½ï¿½ï¿½Wï¿½ï¿½ï¿½ÅÌJï¿½ï¿½ï¿½ï¿½ï¿½Zï¿½ï¿½ï¿½^ï¿½[
	float4			m_shadowMapResolutions;	///< ï¿½Vï¿½ï¿½ï¿½hï¿½Eï¿½}ï¿½bï¿½vï¿½Tï¿½Cï¿½Yï¿½ÏXï¿½pï¿½Ìpï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^ï¿½Îï¿½
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


// --------------------------------
// ï¿½ï¿½ï¿½ï¿½ï¿½_ï¿½[ï¿½oï¿½bï¿½tï¿½@ï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^ï¿½è
struct SRenderBuffer
{
	float4		m_size;						///< xy = ï¿½Tï¿½Cï¿½Y, zw = ï¿½Tï¿½Cï¿½Yï¿½Ìtï¿½ï¿½
};
typedef SRenderBuffer PSRenderBuffer;

#define SHADER_CONST_RENDERBUFFER_SIZE			0
#define SHADER_CONSTANTBUFFER_RENDERBUFFER_SIZE	1


// --------------------------------
// ï¿½ï¿½ï¿½Cï¿½gï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
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



// --------------------------------
// ï¿½}ï¿½eï¿½ï¿½ï¿½Aï¿½ï¿½ï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
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


// --------------------------------
// ï¿½Iï¿½uï¿½Wï¿½Fï¿½Nï¿½gï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^ï¿½è
struct SObjectBase
{
	TMatrix4x4		m_viewWorld ;			///< ( ï¿½rï¿½ï¿½ï¿½[ x ï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½h )ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_world ;				///< ï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½hï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	float4			m_useWeightCount ;		///< ï¿½Xï¿½Lï¿½jï¿½ï¿½ï¿½Oï¿½Ìgï¿½pï¿½Eï¿½Fï¿½Cï¿½gï¿½ï¿½
};
// PSSL ï¿½ï¿½ï¿½Æpï¿½ï¿½ï¿½ï¿½ï¿½Êï¿½ï¿½Èï¿½ï¿½æ¤ï¿½ÈÌÅAï¿½ï¿½ï¿½dï¿½ï¿½ï¿½`ï¿½Éï¿½ï¿½ï¿½.
// SObjectBase ï¿½ï¿½ï¿½ÒWï¿½ï¿½ï¿½ï¿½ï¿½ÛÉÍï¿½ï¿½ï¿½ !!
//struct SObject : SObjectBase
struct SObject
{
	TMatrix4x4		m_viewWorld ;			///< ( ï¿½rï¿½ï¿½ï¿½[ x ï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½h )ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	TMatrix4x4		m_world ;				///< ï¿½ï¿½ï¿½[ï¿½ï¿½ï¿½hï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X
	float4			m_useWeightCount ;		///< ï¿½Xï¿½Lï¿½jï¿½ï¿½ï¿½Oï¿½Ìgï¿½pï¿½Eï¿½Fï¿½Cï¿½gï¿½ï¿½
	float4			m_localParam[4] ;		///< ï¿½ï¿½ï¿½[ï¿½Jï¿½ï¿½ï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^(ï¿½eï¿½ï¿½ï¿½ï¿½ï¿½_ï¿½ï¿½ï¿½ï¿½ï¿½Oï¿½tï¿½Fï¿½[ï¿½Yï¿½Ìï¿½ï¿½[ï¿½Jï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Åï¿½ï¿½p)
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


// --------------------------------
// ï¿½{ï¿½[ï¿½ï¿½ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½Xï¿½zï¿½ï¿½
struct SBone
{
	TMatrix4x3		m_boneMatrices[32];		///< ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X(3x32)
	//TMatrix4x3		m_prevBoneMatrices[32];		///< ï¿½uï¿½ï¿½ï¿½ï¿½ï¿½hï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½X(3x32)
};
typedef SBone VSBone;

#define SHADER_CONST_BLENDMATRIX0				0
#define SHADER_CONST_PREV_BLENDMATRIX0			96
#define SHADER_BLENDMATRIX_SIZE					3
#define SHADER_CONSTANTBUFFER_BONE_SIZE			192


// --------------------------------
// ï¿½Vï¿½Fï¿½[ï¿½fï¿½Bï¿½ï¿½ï¿½Oï¿½Aï¿½|ï¿½Xï¿½gï¿½tï¿½Bï¿½ï¿½ï¿½^ï¿½A2Dï¿½ï¿½ï¿½Åï¿½ï¿½ï¿½ï¿½{ï¿½[ï¿½ï¿½ï¿½ï¿½ï¿½Kï¿½vï¿½ÅÍÈï¿½ï¿½ÌÅAoverlapï¿½Åï¿½ï¿½ï¿½ï¿½æ¤ï¿½Éï¿½ï¿½ï¿½
struct SWork
{
	TMatrix4x4		m_viewInverse;		///< viewInverse (ï¿½Vï¿½Fï¿½[ï¿½fï¿½Bï¿½ï¿½ï¿½Oï¿½Åæ­ï¿½gï¿½ï¿½ï¿½Üí¹ï¿½ï¿½ï¿½j
	TMatrix4x4		m_matrix[8];		///< workMatrix[0]
};

// Make this the same size as the vertex version, but we will use it to upload a bunch of vector data
struct PSWork
{
	float4			m_vectors[36];
};
typedef SWork VSWork;

#define SHADER_CONST_VIEWINVERSE				0
#define SHADER_CONST_WORKMATRIX0				4
#define SHADER_CONSTANTBUFFER_WORK_SIZE			36


// ----------------------------------------------------------------
#ifdef __cplusplus


namespace vconst {
	enum
	{
		// ï¿½Vï¿½Xï¿½eï¿½ï¿½ï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		V_SYSTEMPARAM			= (SHADER_CONST_SYSTEM_PARAM),
		V_RENDERINFO			= (SHADER_CONST_SYSTEM_RENDERINFO),
		V_RENDERBUFFER_SIZE		= (SHADER_CONST_SYSTEM_RENDERBUFFER),
		V_DOMINANTLIGHT_DIR		= (SHADER_CONST_SYSTEM_DOMINANT_LIGHT_DIR),
		// ï¿½Vï¿½[ï¿½ï¿½ï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		M_PROJECTIONVIEW		= (SHADER_CONST_PROJECTIONVIEW),
		M_PROJECTION			= (SHADER_CONST_PROJECTION),
		M_VIEW					= (SHADER_CONST_VIEW),
		M_SHADOWPROJECTION		= (SHADER_CONST_SHADOWPROJECTION),
		M_SHADOWPROJECTION2		= (SHADER_CONST_SHADOWPROJECTION2),
		V_EYEPOS				= (SHADER_CONST_EYEPOS),
		V_PROJECTIONPARAM		= (SHADER_CONST_PROJECTIONPARAM),
		V_VIEWPORTSIZE			= (SHADER_CONST_VIEWPORTSIZE),
		V_EXPOSURE				= (SHADER_CONST_EXPOSURE),
		V_FOGPARAM0				= (SHADER_CONST_FOGPARAM0),
		V_FOGPARAM1				= (SHADER_CONST_FOGPARAM1),
		V_FOGPARAM2				= (SHADER_CONST_FOGPARAM2),
		V_FOGCOLOR				= (SHADER_CONST_FOGCOLOR),
		V_CAMERACENTEROFFSET	= (SHADER_CONST_CAMERACENTEROFFSET),
		V_SHADOWMAPRESOLUTIONS	= (SHADER_CONST_SHADOWMAP_RESOLUTIONS),
		// ï¿½ï¿½ï¿½ï¿½ï¿½_ï¿½[ï¿½oï¿½bï¿½tï¿½@ï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		//V_RENDERBUFFER_SIZE		= (SHADER_CONST_RENDERBUFFER_SIZE),
		// ï¿½ï¿½ï¿½Cï¿½gï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		V_LIGHTPARAM0			= (SHADER_CONST_LIGHTPARAM0),
		V_LIGHTPARAM1			= (SHADER_CONST_LIGHTPARAM1),
		V_LIGHTPARAM2			= (SHADER_CONST_LIGHTPARAM2),
		V_LIGHTPARAM3			= (SHADER_CONST_LIGHTPARAM3),
		V_LIGHTPARAM4			= (SHADER_CONST_LIGHTPARAM4),
		V_LIGHTPARAM5			= (SHADER_CONST_LIGHTPARAM5),
		V_LIGHTPARAM6			= (SHADER_CONST_LIGHTPARAM6),
		V_LIGHTPARAM7			= (SHADER_CONST_LIGHTPARAM7),
		V_LIGHTPARAM8			= (SHADER_CONST_LIGHTPARAM8),
		// ï¿½}ï¿½eï¿½ï¿½ï¿½Aï¿½ï¿½ï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		V_MATERIAL0				= (SHADER_CONST_MATERIAL0),
		V_MATERIAL1				= (SHADER_CONST_MATERIAL1),
		V_MATERIAL2				= (SHADER_CONST_MATERIAL2),
		V_MATERIAL3				= (SHADER_CONST_MATERIAL3),
		V_MATERIAL4				= (SHADER_CONST_MATERIAL4),
		V_MATERIAL5				= (SHADER_CONST_MATERIAL5),
		V_MATERIAL6				= (SHADER_CONST_MATERIAL6),
		V_MATERIAL7				= (SHADER_CONST_MATERIAL7),
		// ï¿½Iï¿½uï¿½Wï¿½Fï¿½Nï¿½gï¿½ÅLï¿½pï¿½ï¿½ï¿½ï¿½ï¿½[ï¿½^
		M_VIEWWORLD				= (SHADER_CONST_VIEWWORLD),
		M_WORLD					= (SHADER_CONST_WORLD),
		V_USEWEIGHTCOUNT		= (SHADER_CONST_USEWEIGHTCOUNT),
		V_LOCALPARAM0			= (SHADER_CONST_LOCALPARAM0),
		V_LOCALPARAM1			= (SHADER_CONST_LOCALPARAM1),
		V_LOCALPARAM2			= (SHADER_CONST_LOCALPARAM2),
		V_LOCALPARAM3			= (SHADER_CONST_LOCALPARAM3),
		// ï¿½{ï¿½[ï¿½ï¿½ï¿½}ï¿½gï¿½ï¿½ï¿½Nï¿½Xï¿½zï¿½ï¿½
		M_BLENDMATRIX0			= (SHADER_CONST_BLENDMATRIX0),
		M_PREV_BLENDMATRIX0		= (SHADER_CONST_PREV_BLENDMATRIX0),
		// ï¿½ï¿½ï¿½[ï¿½N
		M_VIEWINVERSE			= (SHADER_CONST_VIEWINVERSE),
		M_WORKMATRIX0			= (SHADER_CONST_WORKMATRIX0),
	};
}	// namespace vconst


namespace cbuf {
	enum
	{
		SYSTEM			= (SHADER_CONSTANTBUFFER_SYSTEM),
		RENDERBUFFER	= (SHADER_CONSTANTBUFFER_RENDERBUFFER),
		SCENE			= (SHADER_CONSTANTBUFFER_SCENE),
		LIGHTS			= (SHADER_CONSTANTBUFFER_LIGHTS),
		MATERIAL		= (SHADER_CONSTANTBUFFER_MATERIAL),
		OBJECT			= (SHADER_CONSTANTBUFFER_OBJECT),
		BONES			= (SHADER_CONSTANTBUFFER_BONES),
		WORK			= (SHADER_CONSTANTBUFFER_WORK),
		
		// legacy
		LIGHT			= LIGHTS,
	};
}	// namespace cbufffer
	
#endif	// ifdef __cplusplus

// ï¿½Vï¿½Xï¿½eï¿½ï¿½ï¿½pï¿½Ìï¿½ï¿½Wï¿½Xï¿½^
#define TEXUNIT_VOLUMEFOG	TEXUNIT12	// DefferredShadingï¿½È~ï¿½ï¿½ï¿½ï¿½Draw2Dï¿½ÜÅÍgï¿½ï¿½
#define TEXUNIT_DEPTH		TEXUNIT13
#define TEXUNIT_SHADOW		TEXUNIT14


#endif	// ifndef _DG_SHADER_DEF_FOR_DIRECTX11_GEN_H_
