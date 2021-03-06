#pragma once
#include "soxCore.h"
#include "Planet.h"
#include "FlyCamera.h"

class FlyCamera;

class Application
{
public:
	Application(const glm::ivec2& a_resolution, const char* a_name);
	~Application();

	int run();

protected:

	int initialize();

	bool update(double deltaTime);

	void iterate();

	void render();

	int terminate();

	double m_deltaTime;

	void InitTexture();
	void UpdateTexture();

	void InitPhong();
	void UpdatePhong();

	void InitNormalMap();
	void UpdateNormalMap();

	// Initialise various shapes.
	void createQuad();
	void createCube();
	void createCylinder();

	bool CreateBunny();

	void RenderBunny();

	void RenderBuddha();

	void CreateSpear();

	void RenderSpear(aie::ShaderProgram* shaderType);

	void RenderTree(aie::ShaderProgram* shaderType);

	void RenderLargeRock(aie::ShaderProgram* shaderType);

	void RenderHouse(aie::ShaderProgram* shaderType);

	void RenderGrass(aie::ShaderProgram* shaderType);



	glm::ivec2 m_windowResolution;
	const char* m_windowName;
	GLFWmonitor** screens;
	int screenCount = 0;
	GLFWwindow* window;
	sns::clock m_clock;
	sns::time m_startTime;
	sns::time m_currentTime;
	sns::time m_previousTime;
	glm::mat4 view;
	glm::mat4 projection;
	FlyCamera* m_flyCam;
	Planet m_planet;

	//----------Shader----------
	aie::ShaderProgram m_shader;
	aie::ShaderProgram m_texturedShader;
	aie::ShaderProgram m_phongShader;
	aie::ShaderProgram m_normalMapShader;

	glm::mat4 m_quadTransform;

	//----------Light----------
	struct Light {
		glm::vec3 direction;
		glm::vec3 diffuse;
		glm::vec3 specular;
	};

	Light m_light;
	glm::vec3 m_ambientLight;


	//----------Texture---------
	aie::Texture m_gridTexture;


	//----------Mesh------------
	Mesh m_quadMesh;
	Mesh m_cubeMesh;
	Mesh m_circleMesh;
	Mesh m_cylinderMesh;


	//----------imgui-----------
	//ImGuiWindow* m_PanelGameObject;
	

	//----------OBJ-------------
	aie::OBJMesh m_bunnyMesh;
	glm::mat4 m_bunnyTransform;

	aie::OBJMesh m_buddhaMesh;
	glm::mat4 m_buddhaTransform;

	aie::OBJMesh m_spearMesh;
	glm::mat4 m_spearTransform;

	//------Actual Meshes-------
	aie::OBJMesh m_treeMesh;
	glm::mat4 m_treeTransform;

	aie::OBJMesh m_largeStoneMesh;
	glm::mat4 m_largeStoneTransform;

	aie::OBJMesh m_mediumStoneMesh;
	glm::mat4 m_mediumStoneTransform;

	aie::OBJMesh m_logGrassStoneMesh;
	glm::mat4 m_logGrassStoneTransform;

	aie::OBJMesh m_houseMesh;
	glm::mat4 m_houseTransform;

	aie::OBJMesh m_grassMesh;
	glm::mat4 m_grassTransform;
};

