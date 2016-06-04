/*
** Character.cpp for Character in /home/drozdz_b/Documents/TestIrrlitch3
**
** Made by drozdz_b
** Login   <drozdz_b@epitech.net>
**
** Started on  Thu May 26 15:17:50 2016 drozdz_b
// Last update Sun Jun  5 01:28:14 2016 Sacha Sacha Monderer
*/

#include "Character.hpp"

/*
** Construtors & Destructor
*/
Character::Character(scene::ISceneNode* node)
: Object(node)
{
}

Character::Character(scene::ISceneManager* smgr, video::IVideoDriver * driver)
: Object(NULL)
{
  scene::IAnimatedMesh *bomber = smgr->getMesh("imgs/tris.md2");
  //bomber->setFrameLoop(0, 10);
  _nodeAnim = smgr->addAnimatedMeshSceneNode(bomber);
  _size = core::vector3df(1, 1, 1);
  _col = smgr->getSceneCollisionManager();
  _smgr = smgr;
  _driver = driver;
  if (_nodeAnim)
  {
      _nodeAnim->setMaterialTexture(0, driver->getTexture("imgs/Bomber.PCX"));
      _nodeAnim->setMaterialFlag(video::EMF_LIGHTING, false);
      _nodeAnim->setScale(core::vector3df(0.03f, 0.03f, 0.03f));
      _nodeAnim->setFrameLoop(400, 600);
      _nodeAnim->setAnimationSpeed(30);
      _moving = false;
      _movingPreced = false;
  }
}

/*Character::Character(scene::ISceneNode* node, video::IVideoDriver * driver)
: Object(node, driver)
{

}*/

Character::~Character()
{
}

CharacterInfo&	Character::getInfo()
{
  return (this->_info);
}

/*
** Actions of Character
*/
void	Character::move(f32 x, f32 y)
{
    if (x > 0)
      _nodeAnim->setRotation(core::vector3df(0, -30, 0));
    if (x < 0)
      _nodeAnim->setRotation(core::vector3df(0, 150, 0));

    if (_moving)
      _movingPreced = true;
    _moving = true;

    this->_pos = this->_nodeAnim->getPosition();
    this->_pos.X += x;
    this->_pos.Y += y;
    this->_nodeAnim->setPosition(this->_pos);
}

void	Character::move(f32 x, f32 y, f32 z)
{
    if (x > 0)
      _nodeAnim->setRotation(core::vector3df(0, -30, 0));
    if (x < 0)
      _nodeAnim->setRotation(core::vector3df(0, 30, 0));
    if (z > 0)
      _nodeAnim->setRotation(core::vector3df(0, -60, 0));
    if (z < 0)
      _nodeAnim->setRotation(core::vector3df(0, 60, 0));

    if (_moving)
      _movingPreced = true;
    _moving = true;

    this->_pos = this->_nodeAnim->getPosition();
    this->_pos.X += x;
    this->_pos.Y += y;
    this->_pos.Z += z;
    this->_nodeAnim->setPosition(this->_pos);
}

void	Character::stati()
{
  if (!_moving)
    _movingPreced = false;
  _moving = false;
}

void	Character::updateAnim()
{
  if (_moving && _movingPreced == false)
  {
    _node->setFrameLoop(160, 180);
    _node->setAnimationSpeed(100);
  }
  else if (!_moving && _movingPreced)
  {
      _node->setFrameLoop(400, 600);
      _node->setAnimationSpeed(30);
  }
}

void	Character::putBomb()
{
  Bomb	*bomb = new Bomb(_smgr, _driver);
  core::vector3df	pos;

  if (bomb)
  {
    _bombList.push_back(bomb);
    bomb->getNode()->setPosition(_node->getPosition() + core::vector3df(5, -2, 5));
    bomb->addCollision(this);
  }
}

void	Character::update()
{
  std::list<Bomb *>::iterator	it;
  this->updateAnim();
}

void		Character::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector)
  {
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        core::vector3df(1,1,1),core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _node->addAnimator(anim);
    anim->drop();
  }
}

void		Character::setCollision(scene::ISceneNode *mapNode, scene::IMesh *mesh, scene::ISceneManager *smgr, core::vector3df	vect)
{
  scene::ITriangleSelector *selector =
    smgr->createOctreeTriangleSelector(mesh, mapNode, 128);
  if (selector)
  {
    mapNode->setTriangleSelector(selector);
    scene::ISceneNodeAnimator	*anim =
      smgr->createCollisionResponseAnimator(selector, mapNode,
        vect,core::vector3df(0,0,0),
        core::vector3df(0,0,0));
    selector->drop();
    _node->addAnimator(anim);
    anim->drop();
  }
}
