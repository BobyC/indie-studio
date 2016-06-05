//
// Core.cpp for  in /home/foncel_a/rendu/TEK2/CPP/CPP2/cpp_indie_studio
// 
// Made by Anaïs Foncel
// Login   <foncel_a@epitech.net>
// 
// Started on  Thu Apr 28 12:53:24 2016 Anaïs Foncel
// Last update Thu Apr 28 12:55:15 2016 Anaïs Foncel
//

#include "Core.hh"

bool onPause;

Core::Core(IrrlichtDevice * const device)
	:	_device(device)
{
	initData();
	initScene();
}

Core::~Core()
{

}

void Core::run()
{
	while (_device->run())
	  {
		_driver->beginScene(true, true, 0);
		_smgr->drawAll();
		Manager::MenuManager::getInstance()->render();
		if (!onPause)
			Manager::GameManager::getInstance()->play();
		_driver->endScene();
	  }
	  _device->drop();
}

void Core::initData()
{
	_smgr = _device->getSceneManager();
	_env = _device->getGUIEnvironment();
	_driver = _device->getVideoDriver();
	_driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);
	Manager::MenuManager::createManager(_device);
	onPause = true;
}

/*
 * Temporary function
*/
void	Core::initScene()
{
	/*
	core::dimension2d<f32> tileSize(1, 1);
	core::dimension2d<u32>   tileCount(50, 50);

	 IMesh			*plane = _smgr->getGeometryCreator()->createPlaneMesh(tileSize, tileCount);
	 IMeshSceneNode	*node = _smgr->addMeshSceneNode(plane);

	  Plan plan(_smgr, _driver);

	  IMesh *cube = _smgr->getGeometryCreator()->createCubeMesh();
	  Box box(_smgr, _driver);
	  Box box2(_smgr, _driver);
	  //Bomb bomb(_smgr, _driver);
	  box2.setPosition(0,0,-20);
	  //bomb.setPosition(0,0, -20);
	Character obj(_smgr, _driver);
	obj.setCollision(box.getNode(),
	_smgr->getGeometryCreator()->createCubeMesh(), _smgr);
	obj.setCollision(box2.getNode(),
	_smgr->getGeometryCreator()->createCubeMesh(), _smgr);

   obj.setCollision(_node, _plane, _smgr);
	layerController player(&obj, NULL, _device);

	 if (node)
	   {
		 node->setMaterialFlag(EMF_LIGHTING, false);
		  node->setMD2Animation(EMAT_STAND);
		 node->setMaterialTexture(0, _driver->getTexture("WoodChips01_D.tga"));
	   }

	Map	map(_smgr, _driver);

	_driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, false);

	scene::ISceneNode* skybox= _smgr->addSkyBoxSceneNode(
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_up.jpg"),
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_dn.jpg"),
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_lf.jpg"),
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_rt.jpg"),
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_ft.jpg"),
							   _driver->getTexture("../../irrlicht-1.8.3/media/irrlicht2_bk.jpg"));

	scene::ISceneNode* skydome= _smgr->addSkyDomeSceneNode(_driver->getTexture("../../irrlicht-1.8.3/media/skydome.jpg"),16,8,0.95f,2.0f);

	_driver->setTextureCreationFlag(ETCF_CREATE_MIP_MAPS, true);

//	(void)skybox;
//	(void)skydome;
	_smgr->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
	//smgr->addCameraSceneNode(0, vector3df(10, 30, -40), vector3df(0, 10, 0));
	*/
	_smgr->addSkyBoxSceneNode(
							   _driver->getTexture("imgs/irrlicht2_up.jpg"),
							   _driver->getTexture("imgs/irrlicht2_dn.jpg"),
							   _driver->getTexture("imgs/irrlicht2_lf.jpg"),
							   _driver->getTexture("imgs/irrlicht2_rt.jpg"),
							   _driver->getTexture("imgs/irrlicht2_ft.jpg"),
							   _driver->getTexture("imgs/irrlicht2_bk.jpg"));

	_smgr->addSkyDomeSceneNode(_driver->getTexture("imgs/skydome.jpg"),16,8,0.95f,2.0f);
}
