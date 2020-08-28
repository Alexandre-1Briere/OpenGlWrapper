#pragma once

#ifdef NG_PLATEFORM_WINDOWS
extern Engine::Application* Engine::CreateApplication();

void main(int argc, char** argv) {
	Engine::Log::Init();

	Engine::Application* app = Engine::CreateApplication();
	app->Run();
	delete app;
}
#endif // NG_PLATEFORM_WINDOWS

