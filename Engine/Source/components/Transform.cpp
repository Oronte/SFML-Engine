#include "Transform.h"

using namespace engine;

engine::Transform::Transform(Actor* _owner, const TransformData& _transform)
	: Component(_owner)
{
	transform = _transform;
}
