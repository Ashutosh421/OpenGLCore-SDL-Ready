#include "Material.h"

namespace AREngine {

	Material::Material()
	{
		ambience = Color::white;
		diffuse = Color::white;
		specular = Color::white;
		ambienceStrength = 0.5f;
		diffuseStrength = 1;
		specularStrength = 1;
	}

	void Material::setAmbience(const Color& ambienceColor) {
		this->ambience = ambienceColor;
	}

	void Material::setDiffuse(const Color& diffuse) {
		this->diffuse = diffuse;
	}

	void Material::setSpecular(const Color& specular) {
		this->specular = specular;
	}

	Color Material::getAmbience() {
		return this->ambience;
	}

	Color Material::getDiffuse() {
		return this->diffuse;
	}

	Color Material::getSpecular() {
		return this->specular;
	}

	void Material::setAmbienceStrength(const float& ambienceStrength) {
		this->ambienceStrength = ambienceStrength;
	}

	void Material::setDiffuseStrength(const float& diffuseStrength) {
		this->diffuseStrength = diffuseStrength;
	}

	void Material::setSpecularStrength(const float& specularStrength) {
		this->specularStrength = specularStrength;
	}

	float Material::getAmbienceStrength() {
		return this->ambienceStrength;
	}

	float Material::getDiffuseStrength() {
		return this->diffuseStrength;
	}

	float Material::getSpecularStrength() {
		return this->specularStrength;
	}

	Material::~Material()
	{

	}
}

