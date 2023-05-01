from django.contrib.auth.views import LoginView, LogoutView
from django.urls import path

app_name = 'common'

urlpatterns = [
    path('login', LoginView.as_view(template_name='auth/login.html'), name='login'),
    path('logout', LogoutView.as_view(), name='logout'),
]
