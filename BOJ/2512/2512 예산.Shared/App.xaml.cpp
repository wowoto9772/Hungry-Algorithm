//
// App.xaml.cpp
// App 클래스의 구현입니다.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace _2512_예산;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Media::Animation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// 새 응용 프로그램 템플릿에 대한 설명은 http://go.microsoft.com/fwlink/?LinkId=234227에 나와 있습니다.

/// <summary>
/// singleton 응용 프로그램 개체를 초기화합니다. 이것은 실행되는 작성 코드의 첫 번째
/// 줄이며 따라서 main() 또는 WinMain()과 논리적으로 동일합니다.
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// 최종 사용자가 응용 프로그램을 정상적으로 시작할 때 호출됩니다. 다른 진입점은
/// 특정 파일을 열거나, 검색 결과를 표시하는 등 응용 프로그램을 시작할 때
/// 사용됩니다.
/// </summary>
/// <param name="e">시작 요청 및 프로세스에 대한 정보입니다.</param>
void App::OnLaunched(LaunchActivatedEventArgs^ e)
{
#if _DEBUG
	if (IsDebuggerPresent())
	{
		DebugSettings->EnableFrameRateCounter = true;
	}
#endif

	auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

	// 창에 콘텐츠가 이미 있는 경우 앱 초기화를 반복하지 말고,
	// 창이 활성화되어 있는지 확인하십시오.
	if (rootFrame == nullptr)
	{
		// 탐색 상황에 맞게 사용되는 프레임을 만들어 이를
		// SuspensionManager 키에 연결합니다.
		rootFrame = ref new Frame();

		// TODO: 이 값을 응용 프로그램에 적절한 캐시 크기로 변경합니다.
		rootFrame->CacheSize = 1;

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// TODO: 해당하는 경우에만 저장된 세션 상태를 복원하고 복원이
			// 완료되면 마지막 시작 단계를 예약합니다.
		}

		// 현재 창에 프레임 넣기
		Window::Current->Content = rootFrame;
	}

	if (rootFrame->Content == nullptr)
	{
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		// 시작을 위해 턴스타일 탐색을 제거합니다.
		if (rootFrame->ContentTransitions != nullptr)
		{
			_transitions = ref new TransitionCollection();
			for (auto transition : rootFrame->ContentTransitions)
			{
				_transitions->Append(transition);
			}
		}

		rootFrame->ContentTransitions = nullptr;
		_firstNavigatedToken = rootFrame->Navigated += ref new NavigatedEventHandler(this, &App::RootFrame_FirstNavigated);
#endif

		// 탐색 스택이 복원되지 않으면 첫 번째 페이지로 돌아가고
		// 필요한 정보를 탐색 매개 변수로 전달하여 새 페이지를
		// 구성합니다.
		if (!rootFrame->Navigate(MainPage::typeid, e->Arguments))
		{
			throw ref new FailureException("Failed to create initial page");
		}
	}

	// 현재 창이 활성인지 확인
	Window::Current->Activate();
}

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
/// <summary>
/// 응용 프로그램이 시작된 후 콘텐츠 전환을 복구합니다.
/// </summary>
void App::RootFrame_FirstNavigated(Object^ sender, NavigationEventArgs^ e)
{
	auto rootFrame = safe_cast<Frame^>(sender);

	TransitionCollection^ newTransitions;
	if (_transitions == nullptr)
	{
		newTransitions = ref new TransitionCollection();
		newTransitions->Append(ref new NavigationThemeTransition());
	}
	else
	{
		newTransitions = _transitions;
	}

	rootFrame->ContentTransitions = newTransitions;

	rootFrame->Navigated -= _firstNavigatedToken;
}
#endif

/// <summary>
/// 응용 프로그램 실행이 일시 중지된 경우 호출됩니다. 응용 프로그램이 종료될지
/// 또는 메모리 콘텐츠를 변경하지 않고 다시 시작할지 여부를 결정하지 않은 채
/// 응용 프로그램 상태가 저장됩니다.
/// </summary>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void) sender;	// 사용하지 않는 매개 변수
	(void) e;		// 사용하지 않는 매개 변수

	// TODO: 응용 프로그램 상태를 저장하고 백그라운드 작업을 모두 중지합니다.
}