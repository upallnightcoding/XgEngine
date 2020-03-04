#pragma once

#include "Xg.h"

struct XgVertex {
	vec3 point;
	vec3 normal;
	vec2 texture;
};

namespace std {
	template<> struct hash<XgVertex> {
		size_t operator()(XgVertex const& vertex) const {
			return ((hash<glm::vec3>()(vertex.point) ^ (hash<glm::vec3>()(vertex.normal) << 1)) >> 1) ^ (hash<glm::vec2>()(vertex.texture) << 1);
		}
	};
}