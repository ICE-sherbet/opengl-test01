#include "SolidShapeIndex.h"

SolidShapeIndex::SolidShapeIndex(GLint size, GLsizei vertexcount, const Object::Vertex* vertex,
	GLsizei indexcount, const GLuint* index) :ShapeIndex(size, vertexcount, vertex, indexcount, index)
{	}
 void SolidShapeIndex::execute() const {
	// �O�p�`�ŕ`�悷��
	glDrawElements(GL_TRIANGLES, indexcount, GL_UNSIGNED_INT, 0);
}