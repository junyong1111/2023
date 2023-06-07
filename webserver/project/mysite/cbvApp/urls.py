from django.urls import path
from . import views
urlpatterns = [
    path('students/', views.StudentList.as_view()),
    path('students/<int:pk>', views.StudnetDetail.as_view()),
]
