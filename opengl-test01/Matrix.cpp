#include "Matrix.h"

Matrix::Matrix() {}
Matrix::Matrix(const GLfloat *a){
	std::copy(a, a + 16, matrix);
}
const GLfloat *Matrix::data() const{return matrix;}

void Matrix::loadIdentity() {
	std::fill(matrix, matrix + 16, 0.0f);
	matrix[0] = matrix[5] = matrix[10] = matrix[15] = 1.0f;
}

void Matrix::setLine(GLint index, vec3 vec) {
	const GLint i(index & 15);
	matrix[0 + i] = vec.x;
	matrix[4 + i] = vec.y;
	matrix[8 + i] = vec.z;
}
Matrix Matrix::identity() {
	Matrix t;
	t.loadIdentity();
	return t;
}

// (x,y,z) ‚¾‚¯•½sˆÚ“®‚·‚é•ÏŠ·s—ñ‚ğì¬‚·‚é
Matrix Matrix::translate(GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;
	t.loadIdentity();
	t[12] = x;
	t[13] = y;
	t[14] = z;

	return t;
}
Matrix Matrix::translate(vec3 vec) {
	return translate(vec.x, vec.y, vec.z);
}

// (x,y,z) ‚¾‚¯Šg‘åk¬‚·‚é•ÏŠ·s—ñ‚ğì¬‚·‚é
Matrix Matrix::scale(GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;
	t.loadIdentity();
	t[0] = x;
	t[5] = y;
	t[10] = z;

	return t;
}
Matrix Matrix::scale(vec3 vec) {
	return scale(vec.x, vec.y, vec.z);
}

// ‚¹‚ñ’f‚ğ‚·‚é•ÏŠ·s—ñ‚ğì¬‚·‚é
Matrix Matrix::shear(GLfloat xy, GLfloat yx, GLfloat xz, GLfloat zx, GLfloat yz, GLfloat zy) {
	Matrix t;
	t.loadIdentity();
	t[1] = yx;
	t[2] = zx;
	t[4] = xy;
	t[6] = zy;
	t[8] = xz;
	t[9] = yz;

	return t;
}
/*
// (x,y,z) ‚¾‚¯À•W²’†S‚Ì‰ñ“]‚·‚é•ÏŠ·s—ñ‚ğì¬‚·‚é
Matrix Matrix::Rotation(GLfloat x, GLfloat y, GLfloat z) {
	Matrix t;
	t.loadIdentity();
	t[0] = x;
	t[5] = y;
	t[10] = z;

	return t;
}
Matrix Matrix::Rotation(vec3 vec) {
	Matrix t;
	t.loadIdentity();
	t[0] = vec.x;
	t[5] = vec.y;
	t[10] = vec.z;

	return t;
}
*/

Matrix Matrix::rotate(GLfloat a, vec3 vec) {
	Matrix t;
	const GLfloat d(vec.length());
	if (d <= 0.0f) return t;
	const vec3 l = vec / d;
	const vec3 l2 = l * l;
	const vec3 m = l * l.roll();
	const vec3 c(cos(a), 1.0f - cos(a), sin(a));
	t.loadIdentity();
	t[0] = (1.0f - l2.x) * c.x + l2.x;
	t[1] = m.x * c.y + l.z * c.z;
	t[2] = m.z * c.y - l.y * c.z;

	t[4] = m.x * c.y - l.z * c.z;
	t[5] = (1.0f - l2.y) * c.x + l2.y;
	t[6] = m.y * c.y + l.x * c.z;

	t[8] = m.z * c.y + l.y * c.z;
	t[9] = m.y * c.y - l.x * c.z;
	t[10] = (1.0f - l2.z) * c.x + l2.z;
	

	return t;
}

Matrix Matrix::operator*(const Matrix& m)const {
	Matrix t;
	for (int i = 0; i < 16; i++)
	{
		const int j(i & 3), k(i & ~3);

		t[i] =
			matrix[0 + j] * m[k + 0] +
			matrix[4 + j] * m[k + 1] +
			matrix[8 + j] * m[k + 2] +
			matrix[12 + j] * m[k + 3];
	}
	return t;
}
Matrix Matrix::lookat(vec3 e, vec3 g, vec3 u) {
	const Matrix tv(translate(e.inverse()));
	const vec3 t = e - g;
	const vec3 r = u.cross(t);
	const vec3 s = t.cross(r);
	
	// s ²‚Ì’·‚³ƒ`ƒFƒbƒN
	const GLfloat s2(s.lengthSquare());
	if (s2 == 0.0f) return tv;

	// ‰ñ“]‚Ì•ÏŠ·s—ñ
	Matrix rv;
	rv.loadIdentity();

	// r ²‚ğ³‹K‰»‚µ‚Ä”z—ñ•Ï”‚ÉŠi”[
	const GLfloat rl(r.length());
	rv.setLine(0, r / rl);

	// s ²‚ğ³‹K‰»‚µ‚Ä”z—ñ•Ï”‚ÉŠi”[
	const GLfloat sl(s.length());
	rv.setLine(1, s / sl);

	// t ²‚ğ³‹K‰»‚µ‚Ä”z—ñ•Ï”‚ÉŠi”[
	const GLfloat tl(t.length());
	rv.setLine(2, t / tl);

	// ‹“_‚Ì•½sˆÚ“®‚Ì•ÏŠ·s—ñ‚É‹ü‚Ì‰ñ“]‚Ì•ÏŠ·s—ñ‚ğæ‚¶‚é
	return rv * tv;


}


Matrix Matrix::orthogonal(GLfloat left, GLfloat right,
	GLfloat bottom, GLfloat top,
	GLfloat zNear, GLfloat zFar)
{
	Matrix t;
	const vec3 d(right - left, top - bottom, zFar - zNear);
	if (d.isNonZero()) {
		t.loadIdentity();
		t[0] = 2.0f / d.x;
		t[5] = 2.0f / d.y;
		t[10] = -2.0f / d.z;
		t[12] = -(right + left) / d.x;
		t[13] = -(top + bottom) / d.y;
		t[14] = -(zFar + zNear) / d.z;
	}

	return t;
}
Matrix Matrix::frustum(GLfloat left, GLfloat right,
	GLfloat bottom, GLfloat top,
	GLfloat zNear, GLfloat zFar)
{
	Matrix t;
	const vec3 d(right - left, top - bottom, zFar - zNear);
	if (d.isNonZero()) {
		t.loadIdentity();
		t[0] = 2.0f* zNear / d.x;
		t[5] = 2.0f * zNear / d.y;
		t[8] = (right + left) / d.z;
		t[9] = -(top + bottom) / d.x;
		t[10] = -(zFar + zNear) / d.y;
		t[11] = -1.0f;
		t[14] = -2.0f * zFar * zNear / d.z;
		t[15] = 0.0f;
	}

	return t;
}

// ‰æŠp‚ğw’è‚µ‚Ä“§‹“Š‰e•ÏŠ·s—ñ‚ğì¬‚·‚é
Matrix Matrix::perspective(GLfloat fovy, GLfloat aspect,
	GLfloat zNear, GLfloat zFar)
{
	Matrix t;
	const GLfloat dz(zFar - zNear);
	if (dz != 0.0f)
	{
		t.loadIdentity();
		t[5] = 1.0f / tan(fovy * 0.5f);
		t[0] = t[5] / aspect;
		t[10] = -(zFar + zNear) / dz;
		t[11] = -1.0f;
		t[14] = -2.0f * zFar * zNear / dz;
		t[15] = 0.0f;
	}
	return t;
}
