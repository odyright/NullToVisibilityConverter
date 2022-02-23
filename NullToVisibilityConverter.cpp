#include "pch.h"
#include "NullToVisibilityConverter.h"
#include "NullToVisibilityConverter.g.cpp"

using namespace winrt::Windows;
using namespace winrt::Windows::UI::Xaml;

namespace winrt::TD2_WinUI3::implementation
{
    /*Visibility NullValue{ Visibility::Collapsed()};
    Visibility NonNullValue{ Visibility::Visible()};*/
    DependencyProperty NullToVisibilityConverter::m_nullValueProperty = DependencyProperty::Register(L"NullValue", winrt::xaml_typename<IInspectable>(), winrt::xaml_typename <TD2_WinUI3::NullToVisibilityConverter>(), PropertyMetadata(nullptr));
    DependencyProperty NullToVisibilityConverter::m_nonNullValueProperty = DependencyProperty::Register(L"NonNullValue", winrt::xaml_typename<IInspectable>(), winrt::xaml_typename <TD2_WinUI3::NullToVisibilityConverter>(), PropertyMetadata(nullptr));


    Windows::Foundation::IInspectable NullToVisibilityConverter::Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& /* targetType */, Windows::Foundation::IInspectable const&  parameter , hstring const& /* language */)
    {
        // Retrieve the value as  String.
        return (value == nullptr) ? NullValue() : NonNullValue();
    }

    Windows::Foundation::IInspectable NullToVisibilityConverter::ConvertBack(Windows::Foundation::IInspectable const& /* value */, Windows::UI::Xaml::Interop::TypeName const& /* targetType */, Windows::Foundation::IInspectable const& /* parameter */, hstring const& /* language */)
    {
        throw hresult_not_implemented();
    }
}