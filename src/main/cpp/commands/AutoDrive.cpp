#include "commands/AutoDrive.h"

Intake::Intake() : test{0}
{
}

void Intake::Initialize()
{

}

void Intake::Execute()
{
	test.Set(1);
}

bool Intake::IsFinished()
{
	return true;
}