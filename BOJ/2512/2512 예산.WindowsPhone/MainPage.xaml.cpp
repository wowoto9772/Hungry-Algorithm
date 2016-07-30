//
// MainPage.xaml.cpp
// MainPage 클래스의 구현입니다.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace _2512_예산;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// 빈 페이지 항목 템플릿에 대한 설명은 http://go.microsoft.com/fwlink/?LinkId=234238에 나와 있습니다.

MainPage::MainPage()
{
	InitializeComponent();
}

/// <summary>
/// 이 페이지가 프레임에 표시되려고 할 때 호출됩니다.
/// </summary>
/// <param name="e">페이지에 도달한 방법을 설명하는 이벤트 데이터입니다. Parameter
/// 속성은 일반적으로 페이지를 구성하는 데 사용됩니다.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// 사용하지 않는 매개 변수

	// TODO: 여기에 표시할 페이지를 준비합니다.

	// TODO: 응용 프로그램에 여러 페이지가 포함된 경우
	// Windows.Phone.UI.Input.HardwareButtons.BackPressed 이벤트에 등록하여
	// Windows::Phone::UI::Input::HardwareButtons.BackPressed 이벤트.
	// 일부 템플릿에서 제공하는 NavigationHelper를 사용할 경우
	// 이 이벤트가 자동으로 처리됩니다.
}
