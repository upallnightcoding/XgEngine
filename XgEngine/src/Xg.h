#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/hash.hpp>

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <fstream>

// TODO Only use one constants file
#include "XgConstants.h"
#include "XgConstant.h"

using namespace std;
using namespace glm;