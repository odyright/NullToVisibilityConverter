#include "pch.h"
#include "NullToVisibilityConverter.h"
#if __has_include("NullToVisibilityConverter.g.cpp")
#include "NullToVisibilityConverter.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::TD2_WinUI3::implementation
{
    Windows::Foundation::IInspectable NullToVisibilityConverter::Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& /* targetType */, Windows::Foundation::IInspectable const& parameter, hstring const& /* language */)
    {
        return box_value(value == nullptr ? nullValue : nonNullValue);
    }

    Windows::Foundation::IInspectable NullToVisibilityConverter::ConvertBack(Windows::Foundation::IInspectable const& /* value */, Windows::UI::Xaml::Interop::TypeName const& /* targetType */, Windows::Foundation::IInspectable const& /* parameter */, hstring const& /* language */)
    {
        throw hresult_not_implemented();
    }

    Microsoft::UI::Xaml::Visibility NullToVisibilityConverter::NullValue() noexcept
    {
        return nullValue;
    }

    void NullToVisibilityConverter::NullValue(Microsoft::UI::Xaml::Visibility value) noexcept
    {
        nullValue = value;
    }

    Microsoft::UI::Xaml::Visibility NullToVisibilityConverter::NonNullValue() noexcept
    {
        return nonNullValue;
    }

    void NullToVisibilityConverter::NonNullValue(Microsoft::UI::Xaml::Visibility value) noexcept
    {
        nonNullValue = value;
    }
}