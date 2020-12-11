/*
 * GLDemoWindow.h
 *
 *  Created on: 7 нояб. 2020 г.
 *      Author: unyuu
 */

#ifndef GLDEMOWINDOW_H_
#define GLDEMOWINDOW_H_

#include <GL/gl.h>
#include <GL/glu.h>

#include "Window.h"

#include "Texture.h"

#include <vector>

using VertexVector = std::vector<std::vector<double>>;
using FaceVector = std::vector<std::vector<int>>;
using NormalVector = std::vector<std::vector<double>>;
using ColorVector = std::vector<std::vector<float>>;
using TexCoordVector = std::vector<std::vector<std::vector<double>>>;

struct Model
{
	VertexVector & vertices;
	FaceVector & faces;
	NormalVector & normals;
	ColorVector & colors;
	TexCoordVector & tex_coords;
};


class GLDemoWindow: public Window
{
protected:
	double _camera_z { 0. };
	double _angle { 0. };
	double _tilt_phase;

	Texture _home;
	Texture _green;
	Texture _brown;
	Texture _orange;

	void draw_model(Model &model);

public:
	GLDemoWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~GLDemoWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* GLDEMOWINDOW_H_ */
