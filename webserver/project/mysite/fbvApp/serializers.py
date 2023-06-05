from rest_framework import serializers
from fbvApp.models import Student

# StudentSerializer

class StudentSerializer(serializers.ModelSerializer):
    class Meta:
        model = Student
        fields = ['id', 'name', 'score']