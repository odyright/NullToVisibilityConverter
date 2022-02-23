#pragma once

#include "winrt/Microsoft.UI.Xaml.h"
#include "winrt/Microsoft.UI.Xaml.Markup.h"
#include "winrt/Microsoft.UI.Xaml.Controls.Primitives.h"
#include "NullToVisibilityConverter.g.h"

namespace winrt::TD2_WinUI3::implementation
{
    struct NullToVisibilityConverter : NullToVisibilityConverterT<NullToVisibilityConverter>
    {
        NullToVisibilityConverter() 
        {
            NullValue(winrt::box_value(Microsoft::UI::Xaml::Visibility::Collapsed));
            NonNullValue(winrt::box_value(Microsoft::UI::Xaml::Visibility::Visible));
        };

        IInspectable NullValue() { return  GetValue(m_nullValueProperty); };
        void NullValue(IInspectable const& value) { SetValue(m_nullValueProperty, value); };
        static DependencyProperty NullValueProperty() { return m_nullValueProperty; };

        IInspectable NonNullValue() { return  GetValue(m_nonNullValueProperty); };
        void NonNullValue(IInspectable const& value) { SetValue(m_nonNullValueProperty, value); };
        static DependencyProperty NonNullValueProperty() { return m_nonNullValueProperty; };

        Windows::Foundation::IInspectable Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
        Windows::Foundation::IInspectable ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);

    private:
        static DependencyProperty m_nullValueProperty;
        static DependencyProperty m_nonNullValueProperty;
    };
}

namespace winrt::TD2_WinUI3::factory_implementation
{
    struct NullToVisibilityConverter : NullToVisibilityConverterT<NullToVisibilityConverter, implementation::NullToVisibilityConverter>
    {
    };
}
